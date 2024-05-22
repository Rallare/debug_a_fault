/*
 * Copyright (c) 2017 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/__assert.h>
#include <string.h>

void fault(void) {
	uint32_t * outofbounds_read = (uint32_t *)0;
	*outofbounds_read = 1234;
}

int main(void)
{
	printk("Hello Faulting project! Running on board %s\n", CONFIG_BOARD);
	while (1) {
		printk("\nWill fault in ... ");
		for (int i = 5; i >= 0; i--) {
			printk(" %d",i);
			if (i == 0) {
				printk("\n");
				fault();
			}
			k_msleep(1000);
		}
	}
	return 0;
}