# SPDX-License-Identifier: BSD-3-Clause
LK2ND_PROJECT := lk1st
LK2ND_DISPLAY ?= cont-splash
include lk2nd/project/base.mk
ENABLE_FBCON_DISPLAY_MSG := 1

# The device module is useless on lk1st if no DTB is bundled
ifneq ($(LK2ND_BUNDLE_DTB),)
MODULES += lk2nd/device
else
$(info NOTE: Device module is disabled without bundling a device DTB (LK2ND_BUNDLE_DTB))
endif
