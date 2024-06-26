/*
 * Copyright (C) 2015 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

/**
 * FuDfuSector:
 *
 * This object represents an sector of memory at a specific address on the
 * device itself.
 *
 * This allows relocatable data segments to be stored in different
 * locations on the device itself.
 *
 * You can think of these objects as flash segments on devices, where a
 * complete block can be erased and then written to.
 *
 * See also: [class@FuChunk]
 */

#include "config.h"

#include <fwupdplugin.h>

#include <stdio.h>
#include <string.h>

#include "fu-dfu-common.h"
#include "fu-dfu-sector.h"

typedef struct {
	guint32 address;
	guint32 size;
	guint32 size_left;
	guint16 zone;
	guint16 number;
	FuDfuSectorCap cap;
} FuDfuSectorPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(FuDfuSector, fu_dfu_sector, G_TYPE_OBJECT)
#define GET_PRIVATE(o) (fu_dfu_sector_get_instance_private(o))

static void
fu_dfu_sector_class_init(FuDfuSectorClass *klass)
{
}

static void
fu_dfu_sector_init(FuDfuSector *self)
{
}

/**
 * fu_dfu_sector_new: (skip)
 * address: the address for the sector
 * size: the size of this sector
 * size_left: the size of the rest of the sector
 * zone: the zone of memory the setor belongs
 * number: the sector number in the zone
 * cap: the #FuDfuSectorCap
 *
 * Creates a new DFU sector object.
 *
 * Returns: a new #FuDfuSector
 **/
FuDfuSector *
fu_dfu_sector_new(guint32 address,
		  guint32 size,
		  guint32 size_left,
		  guint16 zone,
		  guint16 number,
		  FuDfuSectorCap cap)
{
	FuDfuSectorPrivate *priv;
	FuDfuSector *self;
	self = g_object_new(FU_TYPE_DFU_SECTOR, NULL);
	priv = GET_PRIVATE(self);
	priv->address = address;
	priv->size = size;
	priv->size_left = size_left;
	priv->zone = zone;
	priv->number = number;
	priv->cap = cap;
	return self;
}

/**
 * fu_dfu_sector_get_address:
 * @self: a #FuDfuSector
 *
 * Gets the alternate setting.
 *
 * Returns: integer, or 0x00 for unset
 **/
guint32
fu_dfu_sector_get_address(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return priv->address;
}

/**
 * fu_dfu_sector_get_size:
 * @self: a #FuDfuSector
 *
 * Gets the sector size.
 *
 * Returns: integer, or 0x00 for unset
 **/
guint32
fu_dfu_sector_get_size(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return priv->size;
}

/**
 * fu_dfu_sector_get_size_left:
 * @self: a #FuDfuSector
 *
 * Gets the size of the rest of the sector.
 *
 * Returns: integer, or 0x00 for unset
 **/
guint32
fu_dfu_sector_get_size_left(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return priv->size_left;
}

/**
 * fu_dfu_sector_get_zone:
 * @self: a #FuDfuSector
 *
 * Gets the sector zone number.
 *
 * Returns: integer, or 0x00 for unset
 **/
guint16
fu_dfu_sector_get_zone(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return priv->zone;
}

/**
 * fu_dfu_sector_get_number:
 * @self: a #FuDfuSector
 *
 * Gets the sector index number.
 *
 * Returns: integer, or 0x00 for unset
 **/
guint16
fu_dfu_sector_get_number(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return priv->number;
}

/**
 * fu_dfu_sector_get_id:
 * @self: a #FuDfuSector
 *
 * Gets the sector ID which is a combination of the zone and sector number.
 * You can use this number to check if the segment is the 'same' as the last
 * written or read sector.
 *
 * Returns: integer ID, or 0x00 for unset
 **/
guint32
fu_dfu_sector_get_id(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), 0x00);
	return (((guint32)priv->zone) << 16) | priv->number;
}

/**
 * fu_dfu_sector_has_cap:
 * @self: a #FuDfuSector
 * @cap: a #FuDfuSectorCap, e.g. %DFU_SECTOR_CAP_ERASABLE
 *
 * Finds out if the sector has the required capability.
 *
 * Returns: %TRUE if the sector has the capability
 **/
gboolean
fu_dfu_sector_has_cap(FuDfuSector *self, FuDfuSectorCap cap)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), FALSE);
	return (priv->cap & cap) > 0;
}

static gchar *
fu_dfu_sector_cap_to_string(FuDfuSectorCap cap)
{
	GString *str = g_string_new(NULL);
	if (cap & DFU_SECTOR_CAP_READABLE)
		g_string_append(str, "R");
	if (cap & DFU_SECTOR_CAP_ERASABLE)
		g_string_append(str, "E");
	if (cap & DFU_SECTOR_CAP_WRITEABLE)
		g_string_append(str, "W");
	return g_string_free(str, FALSE);
}

/**
 * fu_dfu_sector_to_string:
 * @self: a #FuDfuSector
 *
 * Returns a string representation of the object.
 *
 * Returns: NULL terminated string, or %NULL for invalid
 **/
gchar *
fu_dfu_sector_to_string(FuDfuSector *self)
{
	FuDfuSectorPrivate *priv = GET_PRIVATE(self);
	GString *str;
	g_autofree gchar *caps_str = NULL;

	g_return_val_if_fail(FU_IS_DFU_SECTOR(self), NULL);

	str = g_string_new("");
	caps_str = fu_dfu_sector_cap_to_string(priv->cap);
	g_string_append_printf(str,
			       "Zone:%i, Sec#:%i, Addr:0x%08x, "
			       "Size:0x%04x, Caps:0x%01x [%s]",
			       priv->zone,
			       priv->number,
			       priv->address,
			       priv->size,
			       priv->cap,
			       caps_str);
	return g_string_free(str, FALSE);
}
