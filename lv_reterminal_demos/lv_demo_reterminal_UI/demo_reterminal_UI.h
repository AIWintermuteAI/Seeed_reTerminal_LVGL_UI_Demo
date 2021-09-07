/**
 * @file lv_demo_reTerminal_UI.h
 *
 */

#ifndef DEMO_RETERMINAL_UI_H
#define DEMO_RETERMINAL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../../lvgl/lvgl.h"
#endif

#include "../evdev_lis3dh_acc/evdev_lis3dh_acc.h"

/*********************
 *      DEFINES
 *********************/

/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 0, 0) == 0
#error "lv_demo: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void demo_reTerminal_UI(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*DEMO_RETERMINAL_UI_H*/
