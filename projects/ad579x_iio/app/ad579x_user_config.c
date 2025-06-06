/*************************************************************************//**
 *   @file   ad579x_user_config.c
 *   @brief  User configuration file for AD579x devices
******************************************************************************
* Copyright (c) 2023 Analog Devices, Inc.
* All rights reserved.
*
* This software is proprietary to Analog Devices, Inc. and its licensors.
* By using this software you agree to the terms of the associated
* Analog Devices Software License Agreement.
*****************************************************************************/

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include "ad579x_user_config.h"
#include "app_config.h"

/******************************************************************************/
/********************** Macros and Constants Definition ***********************/
/******************************************************************************/

/******************************************************************************/
/********************** Variables and User Defined Data Types *****************/
/******************************************************************************/

/* Device initialization parameters */
struct ad5791_init_param ad579x_init_params =  {
	.spi_init = {
		.device_id = SPI_DEVICE_ID,
		.max_speed_hz = 22500000, // Max SPI Speed
		.chip_select = SPI_CSB,   // Chip Select
		.mode = NO_OS_SPI_MODE_3, // CPOL = 1, CPHA = 1
		.platform_ops = &spi_ops,
		.extra = &spi_extra_init_params
	},
	.act_device = ACTIVE_DEVICE,
	.gpio_clr = {
		.port = CLR_PORT,
		.number = CLR_PIN,
		.platform_ops = &gpio_ops,
#if(ACTIVE_PLATFORM == STM32_PLATFORM)
		.extra = &stm32_clear_gpio_init_params
#endif
	},
	.gpio_ldac = {
		.port = LDAC_PORT,
		.number = LDAC_PIN,
		.platform_ops = &gpio_ops,
#if(ACTIVE_PLATFORM == STM32_PLATFORM)
		.extra = &stm32_gpio_ldac_init_params
#endif
	},
	.gpio_reset = {
		.port = RESET_PORT,
		.number = RESET_PIN,
		.platform_ops = &gpio_ops,
#if(ACTIVE_PLATFORM == STM32_PLATFORM)
		.extra = &stm32_gpio_reset_init_params
#endif
	}
};
