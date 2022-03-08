/**
   ------------------------------------------------------------------------------
   SPDX License Identifyer: MIT
   ------------------------------------------------------------------------------
   @file   esp_util.h
   @date   02/17/22
   @author Lucas M <contact@luctins.me>
   ------------------------------------------------------------------------------
   @brief ESP 32 specific utility macros
   ------------------------------------------------------------------------------
*/

#ifndef __ESP_UTIL_H__
#define __ESP_UTIL_H__

/*--- Includes-----------------------------------------------------------------*/

#define  UTIL_USE_LOG 0
#include "util.h"

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

/*--- Constants ---------------------------------------------------------------*/

/*--- Macros ------------------------------------------------------------------*/
/** E xpand: macro evaluation layer */
#define _E(arg) arg
/** E xpand: macro evaluation layer */
#define E(arg) _E(arg)

#define CGF_GET(nsp, name) CONFIG_ ## nsp ## _ ## name

#define GPIO_CONFIG(GPIO, MODE)									\
	gpio_pad_select_gpio(GPIO); gpio_set_direction(GPIO, MODE)

/**
   delay in milisseconds wrapper
*/
#define vTaskDelayMs(ms) vTaskDelay(pdMS_TO_TICKS(ms))

#define LOG_FN_TAG(subtag) static const char TAG* = __FUNCTION__ #subtag

#define LOG_TAG(tag) static const char * TAG = tag
#define LOG_TAGF() LOG_TAG(__func__);

/** errors and critical information */
#define LOGE(...) ESP_LOGE(TAG, __VA_ARGS__)
/** warnings and 'near misses' */
#define LOGW(...) ESP_LOGW(TAG, __VA_ARGS__)
/** general information */
#define LOGI(...) ESP_LOGI(TAG, __VA_ARGS__)
/** verbose information */
#define LOGV(...) ESP_LOGV(TAG, __VA_ARGS__)
/** debug information, pointers adresses and variable dumps */
#define LOGD(...) ESP_LOGD(TAG, __VA_ARGS__)

#endif /* __ESP-UTIL_H__ */
/*------------------------------------ EOF ------------------------------------*/
