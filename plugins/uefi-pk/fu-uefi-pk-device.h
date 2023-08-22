/*
 * Copyright (C) 2022 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <fwupdplugin.h>

#define FU_TYPE_UEFI_PK_DEVICE (fu_uefi_pk_device_get_type())
G_DECLARE_FINAL_TYPE(FuUefiPkDevice, fu_uefi_pk_device, FU, UEFI_PK_DEVICE, FuDevice)

FuUefiPkDevice *
fu_uefi_pk_device_new(FuContext *ctx);
