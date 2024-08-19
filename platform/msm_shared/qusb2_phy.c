#include <arch/defines.h>
#include <platform/iomap.h>
#include <qusb2_phy.h>
#include <reg.h>
#include <bits.h>
#include <debug.h>
#include <qtimer.h>
#include <platform.h>

__WEAK int platform_is_msm8994(void) { return 0; }
__WEAK int platform_is_msm8996(void) { return 0; }
__WEAK int platform_is_msm8996sg(void) { return 0; }
__WEAK bool platform_is_mdm9650(void) { return false; }
__WEAK int platform_is_msm8953(void) { return 0; }
__WEAK bool platform_is_sdx20(void) { return false; }

static inline void qusb2_phy_common_config(uint8_t tune2, int se_clock) {
    writel(tune2, QUSB2PHY_PORT_TUNE2);
    writel(0x83, QUSB2PHY_PORT_TUNE3);
    writel(0xC0, QUSB2PHY_PORT_TUNE4);
    writel(0x30, QUSB2PHY_PLL_TUNE);
    writel(0x79, QUSB2PHY_PLL_USER_CTL1);
    writel(0x21, QUSB2PHY_PLL_USER_CTL2);
    writel(0x14, QUSB2PHY_PORT_TEST2);
    writel(0x9F, QUSB2PHY_PLL_AUTOPGM_CTL1);
    writel(0x00, QUSB2PHY_PLL_PWR_CTL);
}

void qusb2_phy_reset(void) {
    uint32_t val;
    uint8_t tune2 = 0xB3;
    int retry = 100;
    int se_clock = 1;
    int status_reg = 0;

#if GCC_RX2_USB2_CLKREF_EN
    writel(readl(GCC_RX2_USB2_CLKREF_EN) & ~0x1, GCC_RX2_USB2_CLKREF_EN);
    dmb();
#endif
    // Block Reset
    val = readl(GCC_QUSB2_PHY_BCR) | BIT(0);
    writel(val, GCC_QUSB2_PHY_BCR);
    udelay(10);
    writel(val & ~BIT(0), GCC_QUSB2_PHY_BCR);

    // Configure AHB2 PHY to wait state
    writel(0x11, PERIPH_SS_AHB2PHY_TOP_CFG);
    dmb();

    // Set CLAMP_N_EN and disable USB PHY
    if (platform_is_sdx20())
        writel(0x23, QUSB2PHY_PWR_CTRL1_SDX20);
    else
        writel(0x23, QUSB2PHY_PORT_POWERDOWN);

    // Determine clock configuration
#if TCSR_PHY_CLK_SCHEME_SEL
    se_clock = readl(TCSR_PHY_CLK_SCHEME_SEL) & 0x1;
#endif

    if (platform_is_msm8996() || platform_is_mdm9650() || platform_is_msm8953()) {
        if (platform_is_msm8996sg()) {
            writel(0xD0, QUSB2PHY_PORT_TUNE1);
        } else {
            writel(0xF8, QUSB2PHY_PORT_TUNE1);
        }

#if QFPROM_CORR_CALIB_ROW12_MSB
        uint8_t fuse_val = (readl(QFPROM_CORR_CALIB_ROW12_MSB) & 0x1E00000) >> 21;
        if (fuse_val) {
            tune2 = (tune2 & 0x0f) | (fuse_val << 4);
        }
#endif
        qusb2_phy_common_config(tune2, se_clock);

        if (platform_is_msm8996sg()) {
            writel(0x02, QUSB2PHY_PORT_TUNE5);
        }
    } else if (platform_is_sdx20()) {
        // SDX20 specific settings
        writel(se_clock ? 0x03 : 0x13, QUSB2PHY_PLL_ANALOG_CONTROLS_TWO_SDX20);
        writel(0x7C, QUSB2PHY_PLL_CLOCK_INVERTERS_SDX20);
        writel(0x80, QUSB2PHY_PLL_CMODE_SDX20);
        writel(0x0a, QUSB2PHY_PLL_LOCK_DELAY_SDX20);
        writel(0x19, QUSB2PHY_PLL_DIGITAL_TIMERS_TWO_SDX20);
        writel(0xa5, QUSB2PHY_TUNE1_SDX20);
        writel(0x09, QUSB2PHY_TUNE2_SDX20);
        writel(0x00, QUSB2PHY_IMP_CTRL1_SDX20);
        writel(0x22, QUSB2PHY_PWR_CTRL1_SDX20);
    } else {
        // Default settings
        writel(0xA0, QUSB2PHY_PORT_TUNE1);
        writel(0xA5, QUSB2PHY_PORT_TUNE2);
        writel(0x81, QUSB2PHY_PORT_TUNE3);
        writel(0x85, QUSB2PHY_PORT_TUNE4);
    }

    if (platform_is_msm8994()) {
        writel(0x0, QUSB2PHY_PORT_UTMI_CTRL2);
    }

    if (platform_is_sdx20()) {
        writel(0x22, QUSB2PHY_PWR_CTRL1_SDX20);
        writel(0x04, QUSB2PHY_DEBUG_CTRL2_SDX20);
        udelay(88);
    } else {
        writel(0x22, QUSB2PHY_PORT_POWERDOWN);
        udelay(150);
    }

#ifdef GCC_RX2_USB2_CLKREF_EN
    if (!se_clock) {
        writel(readl(GCC_RX2_USB2_CLKREF_EN) | 0x1, GCC_RX2_USB2_CLKREF_EN);
        dmb();
    }
#endif

    udelay(100);

    // Check PLL status
    status_reg = platform_is_sdx20() ? QUSB2PHY_DEBUG_STAT5_SDX20 : QUSB2PHY_PLL_STATUS;

    while (!(readl(status_reg) & QUSB2PHY_PLL_LOCK)) {
        retry--;
        if (!retry) {
            dprintf(CRITICAL, "QUSB2PHY failed to lock: %d", readl(QUSB2PHY_PLL_STATUS));
            break;
        }
        udelay(5);
    }
}

