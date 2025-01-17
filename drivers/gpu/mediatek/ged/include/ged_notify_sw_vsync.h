/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef __GED_NOTIFY_SW_VSYNC_H__
#define __GED_NOTIFY_SW_VSYNC_H__

#include "ged_type.h"

extern unsigned int gpu_block;
extern unsigned int gpu_idle;
extern unsigned int gpu_av_loading;

GED_ERROR ged_notify_sw_vsync(GED_VSYNC_TYPE eType,
	struct GED_DVFS_UM_QUERY_PACK *psQueryData);

GED_ERROR ged_notify_sw_vsync_system_init(void);

void ged_notify_sw_vsync_system_exit(void);

void ged_set_backup_timer_timeout(u64 time_out);
void ged_cancel_backup_timer(void);

u64 ged_get_fallback_time(void);

enum gpu_dvfs_policy_state {
	POLICY_STATE_INIT = -1,
	POLICY_STATE_LB = 0,
	POLICY_STATE_FORCE_LB,
	POLICY_STATE_FB,
	POLICY_STATE_LB_FALLBACK,
	POLICY_STATE_FORCE_LB_FALLBACK,
	POLICY_STATE_FB_FALLBACK,
};
enum gpu_dvfs_policy_state ged_get_policy_state(void);
enum gpu_dvfs_policy_state ged_get_prev_policy_state(void);
void ged_set_policy_state(enum gpu_dvfs_policy_state state);
void ged_set_prev_policy_state(enum gpu_dvfs_policy_state state);

#if defined(CONFIG_GPU_MT8167) || defined(CONFIG_GPU_MT8173) ||\
defined(CONFIG_GPU_MT6739) || defined(CONFIG_GPU_MT6761) ||\
defined(CONFIG_GPU_MT6765)
extern void MTKFWDump(void);
#endif

#endif
