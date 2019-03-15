
#ifndef DRV_LED_H__
#define DRV_LED_H__

#include <stdbool.h>
#include <stdint.h>
#include "nrf_drv_common.h"
#include "sdk_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRV_LED_TIMEOUT                 10 // 最小及时单元，单位为 ms

typedef enum
{
    DRV_LED_EVT_STARTED,
    DRV_LED_EVT_DONE,
}drv_led_evt_type_t;

typedef struct 
{
    uint16_t led;   // @ 从 0 到 LEDS_NUMBER
    uint16_t on;    // 亮的时间，单位为: DRV_LED_TIMEOUT
    uint16_t off;   // 灭的时间，单位为: DRV_LED_TIMEOUT
    uint16_t count; // 亮灭次数，单位为: DRV_LED_TIMEOUT，为 0 表示不停的亮灭
}drv_led_config_t;

typedef void(*drv_led_event_handler_t)(drv_led_evt_type_t);

typedef void(*drv_led_error_handler_t)(uint32_t);

#ifdef LED_MULT
#define LED_L1	(0x07)	// 低位的3盏灯
#define LED_L2	(0x38)	// 高位的3盏灯
#endif

//************************************************************************************************************
// 功能描述:   	停止某部分LED
// 函数参数:    index			->		LED编号bits
// 返回值  :	操作结果
//************************************************************************************************************
uint32_t drv_led_area_stop(uint8_t index);

//************************************************************************************************************
// 功能描述:   	熄灭的第几号LED
// 函数参数:    led_num		->		led编号
// 返回值  :	操作结果
//************************************************************************************************************
ret_code_t led_off(uint8_t led_num);

//************************************************************************************************************
// 功能描述:   	点亮的第几号LED
// 函数参数:    led_num		->		led编号
// 返回值  :	无
//************************************************************************************************************
ret_code_t led_on(uint8_t led_num);

//************************************************************************************************************
// 功能描述:   	关闭所有LED
// 函数参数:    无
// 返回值  :	操作结果
//************************************************************************************************************
ret_code_t led_off_all(void);

//************************************************************************************************************
// 功能描述:   	LED驱动初始化
// 函数参数:    handler			->		开始/停止通知
//				error_handler	->		出错处理函数
// 返回值  :	操作结果
//************************************************************************************************************
uint32_t drv_led_init(drv_led_event_handler_t handler, drv_led_error_handler_t error_handler);

//************************************************************************************************************
// 功能描述:   	启动LED，配置各项参数
// 函数参数:    config			->		配置变量
// 返回值  :	操作结果
//************************************************************************************************************
uint32_t drv_led_start(drv_led_config_t config);

//************************************************************************************************************
// 功能描述:   	停止所有LED
// 函数参数:    无
// 返回值  :	操作结果
//************************************************************************************************************
uint32_t drv_led_stop(void);


#ifdef __cplusplus
}
#endif

#endif // DRV_LED_H__

