#ifndef _PANEL_DUKE_WQHD_DUALDSI_CMD_H_
#define _PANEL_DUKE_WQHD_DUALDSI_CMD_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config duke_wqhd_dualdsi_cmd_panel_data = {
	"qcom,mdss_dsi_duke_wqhd_dualdsi_cmd",  //panel_node_id
	"dsi:0:", //panel_controller
	"qcom,mdss-dsi-panel", //panel compatible
	9, //interface
	1, //type
	"DISPLAY_1", //panel_destination 
	0, //orientation
	0, //clockrate
	60, //framerate
	2, //channel_id
	0, //virtualchannel_id
	1, //broadcast_mode
	1, //lp11_init
	0, //init_delay
	0, //dsi_stream
	0, //interleave_mode
	829875000, //bitclock_freq
	0, //operating_mode
	0, //with_enable_gpio
	0, //gpio_state
	"qcom,mdss_dsi_duke_wqhd_dualdsi_cmd" //slave_panel_node_id
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution duke_wqhd_dualdsi_cmd_panel_res = {
	1440, //panel_width
	2560, //panel_height
	76, //hfront_porch
	32, //hback_porch
	16, //hpulse_width
	0, //hsync_skew
	4, //vfront_porch
	2, //vback_porch
	2, //vpulse_width
	0, //hleft_border
	0, //hright_border
	0, //vtop_border
	0, //vbottom_border
	0, //hactive_res
	0, //vactive_res
	0, //invert_data_polarity
	0, //invert_vsync_polarity
	0  //invert_hsync_polarity
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info duke_wqhd_dualdsi_cmd_color = {
	24, //color_format
	0, //color_order
	0xff, //underflow_color
	0, //vorder_color
	0, //pixel_packing
	0  //pixel_alignment
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char duke_wqhd_dualdsi_cmd_on_cmd0[] = {
	0x11, 0x00, 0x05, 0x80
};

static char duke_wqhd_dualdsi_cmd_on_cmd1[] = {
	0x03, 0x00, 0x39, 0xC0,
	0xF0, 0x5A, 0x5A, 0xFF,
};

static char duke_wqhd_dualdsi_cmd_on_cmd2[] = {
	0x04, 0x00, 0x39, 0xC0,
	0xBD, 0x05, 0x02, 0x16,

};

static char duke_wqhd_dualdsi_cmd_on_cmd3[] = {
	0xFF, 0x02, 0x15, 0x80
};

static char duke_wqhd_dualdsi_cmd_on_cmd4[] = {
	0x03, 0x00, 0x39, 0xC0,
	0xF0, 0xA5, 0xA5, 0xFF,
};

static char duke_wqhd_dualdsi_cmd_on_cmd5[] = {
	0x53, 0x20, 0x15, 0x80
};

static char duke_wqhd_dualdsi_cmd_on_cmd6[] = {
	0x51, 0x80, 0x15, 0x80
};

static char duke_wqhd_dualdsi_cmd_on_cmd7[] = {
	0x35, 0xFF, 0x15, 0x80
};

static char duke_wqhd_dualdsi_cmd_on_cmd8[] = {
	0x29, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd duke_wqhd_dualdsi_cmd_on_command[] = {
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd0, 0x78},
	{0x8, duke_wqhd_dualdsi_cmd_on_cmd1, 0x00},
	{0x8, duke_wqhd_dualdsi_cmd_on_cmd2, 0x00},
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd3, 0x00},
	{0x8, duke_wqhd_dualdsi_cmd_on_cmd4, 0x00},
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd5, 0x00},
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd6, 0x00},
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd7, 0x00},
	{0x4, duke_wqhd_dualdsi_cmd_on_cmd8, 0x00}
};

#define DUKE_WQHD_DUALDSI_CMD_ON_COMMAND 9


static char duke_wqhd_dualdsi_cmdoff_cmd0[] = {
	0x28, 0x00, 0x05, 0x80
};

static char duke_wqhd_dualdsi_cmdoff_cmd1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd duke_wqhd_dualdsi_cmd_off_command[] = {
	{0x4, duke_wqhd_dualdsi_cmdoff_cmd0, 0x21},
	{0x4, duke_wqhd_dualdsi_cmdoff_cmd1, 0x00}
};

#define DUKE_WQHD_DUALDSI_CMD_OFF_COMMAND 2


static struct command_state duke_wqhd_dualdsi_cmd_state = {
	0, //oncommand_state
	1  //offcommand_state
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info duke_wqhd_dualdsi_cmd_command_panel = {
	0, //techeck_enable
	1, //tepin_select
	1, //teusing_tepin
	1, //autorefresh_enable
	1, //autorefresh_framenumdiv
	0x2c, //tevsync_rdptr_irqline
	0x3c, //tevsync_continue_lines
	0, //tevsync_startline_divisor
	0, //tepercent_variance
	1, //tedcs_command
	0, //disable_eotafter_hsxfer
	0  //cmdmode_idletime
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info duke_wqhd_dualdsi_cmd_video_panel = {
	1, //hsync_pulse
	0, //hfp_power_mode
	0, //hbp_power_mode
	0, //hsa_power_mode
	1, //bllp_eof_power_mode
	1, //bllp_power_mode
	2, //traffic_mode
	0, //dma_delayafter_vsync
	0x9 //bllp_eof_power
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration duke_wqhd_dualdsi_cmd_lane_config = {
	4, //dsi_lanes
	0, //dsi_lanemap
	1, //lane0_state
	1, //lane1_state
	1, //lane2_state
	1, //lane3_state
	0  //force_clk_lane_hs
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t duke_wqhd_dualdsi_cmd_timings[] = {
	0x97, 0x5A, 0x3E, 0x00, 0x9A, 0x9A, 0x48, 0x5E, 0x4B, 0x03, 0x04, 0x00
};

static struct panel_timing duke_wqhd_dualdsi_cmd_timing_info = {
	0, //dsi_mdp_trigger
	4, //dsi_dma_trigger
	0x5e, //tclk_post
	0x5 //tclk_pre
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence duke_wqhd_dualdsi_cmd_reset_seq = {
	{1, 1, 1, }, //pin_state
	{1, 0, 1, }, //sleep
	20  //pin_direction
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight duke_wqhd_dualdsi_cmd_backlight = {
	1, //bl_interface_type
	1, //bl_min_level
	128, //bl_max_level
	100, //bl_step
	2, //bl_pmic_controltype
	"PMIC_8941" //bl_pmic_model
};

static struct labibb_desc duke_wqhd_dualdsi_cmd_labibb = {
	1, //amoled_panel
	0, //force_config
	4000000, //ibb_min_volt
	4000000, //ibb_max_volt
	4600000, //lab_min_volt
	4600000, //lab_max_volt
	3, //pwr_up_delay
	3, //pwr_down_delay
	1  //ibb_discharge_en
};

#endif /*_PANEL_DUKE_WQHD_DUALDSI_CMD_H_*/