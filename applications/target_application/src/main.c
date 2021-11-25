/**
 * Copyright (c) 2021 Nordic Semiconductor
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr.h>
#include <sys/printk.h>
#include "myproto.h"

void main(void)
{
	printk("Hello World! %d\n", myproto_init());
}
