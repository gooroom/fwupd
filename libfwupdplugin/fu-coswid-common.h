/*
 * Copyright (C) 2022 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <glib.h>

typedef enum {
	FU_COSWID_TAG_TAG_ID,
	FU_COSWID_TAG_SOFTWARE_NAME,
	FU_COSWID_TAG_ENTITY,
	FU_COSWID_TAG_EVIDENCE,
	FU_COSWID_TAG_LINK,
	FU_COSWID_TAG_SOFTWARE_META,
	FU_COSWID_TAG_PAYLOAD,
	FU_COSWID_TAG_HASH,
	FU_COSWID_TAG_CORPUS,
	FU_COSWID_TAG_PATCH,
	FU_COSWID_TAG_MEDIA,
	FU_COSWID_TAG_SUPPLEMENTAL,
	FU_COSWID_TAG_TAG_VERSION,
	FU_COSWID_TAG_SOFTWARE_VERSION,
	FU_COSWID_TAG_VERSION_SCHEME,
	FU_COSWID_TAG_LANG,
	FU_COSWID_TAG_DIRECTORY,
	FU_COSWID_TAG_FILE,
	FU_COSWID_TAG_PROCESS,
	FU_COSWID_TAG_RESOURCE,
	FU_COSWID_TAG_SIZE,
	FU_COSWID_TAG_FILE_VERSION,
	FU_COSWID_TAG_KEY,
	FU_COSWID_TAG_LOCATION,
	FU_COSWID_TAG_FS_NAME,
	FU_COSWID_TAG_ROOT,
	FU_COSWID_TAG_PATH_ELEMENTS,
	FU_COSWID_TAG_PROCESS_NAME,
	FU_COSWID_TAG_PID,
	FU_COSWID_TAG_TYPE,
	FU_COSWID_TAG_MISSING30, /* not in the spec! */
	FU_COSWID_TAG_ENTITY_NAME,
	FU_COSWID_TAG_REG_ID,
	FU_COSWID_TAG_ROLE,
	FU_COSWID_TAG_THUMBPRINT,
	FU_COSWID_TAG_DATE,
	FU_COSWID_TAG_DEVICE_ID,
	FU_COSWID_TAG_ARTIFACT,
	FU_COSWID_TAG_HREF,
	FU_COSWID_TAG_OWNERSHIP,
	FU_COSWID_TAG_REL,
	FU_COSWID_TAG_MEDIA_TYPE,
	FU_COSWID_TAG_USE,
	FU_COSWID_TAG_ACTIVATION_STATUS,
	FU_COSWID_TAG_CHANNEL_TYPE,
	FU_COSWID_TAG_COLLOQUIAL_VERSION,
	FU_COSWID_TAG_DESCRIPTION,
	FU_COSWID_TAG_EDITION,
	FU_COSWID_TAG_ENTITLEMENT_DATA_REQUIRED,
	FU_COSWID_TAG_ENTITLEMENT_KEY,
	FU_COSWID_TAG_GENERATOR,
	FU_COSWID_TAG_PERSISTENT_ID,
	FU_COSWID_TAG_PRODUCT,
	FU_COSWID_TAG_PRODUCT_FAMILY,
	FU_COSWID_TAG_REVISION,
	FU_COSWID_TAG_SUMMARY,
	FU_COSWID_TAG_UNSPSC_CODE,
	FU_COSWID_TAG_UNSPSC_VERSION,
} FuCoswidTag;

typedef enum {
	FU_COSWID_VERSION_SCHEME_UNKNOWN,
	FU_COSWID_VERSION_SCHEME_MULTIPARTNUMERIC,
	FU_COSWID_VERSION_SCHEME_MULTIPARTNUMERIC_SUFFIX,
	FU_COSWID_VERSION_SCHEME_ALPHANUMERIC,
	FU_COSWID_VERSION_SCHEME_DECIMAL,
	FU_COSWID_VERSION_SCHEME_SEMVER = 16384,
} FuCoswidVersionScheme;

typedef enum {
	FU_COSWID_LINK_REL_LICENSE = -2,
	FU_COSWID_LINK_REL_COMPILER = -1,
	FU_COSWID_LINK_REL_UNKNOWN = 0,
	FU_COSWID_LINK_REL_ANCESTOR = 1,
	FU_COSWID_LINK_REL_COMPONENT = 2,
	FU_COSWID_LINK_REL_FEATURE = 3,
	FU_COSWID_LINK_REL_INSTALLATIONMEDIA = 4,
	FU_COSWID_LINK_REL_PACKAGEINSTALLER = 5,
	FU_COSWID_LINK_REL_PARENT = 6,
	FU_COSWID_LINK_REL_PATCHES = 7,
	FU_COSWID_LINK_REL_REQUIRES = 8,
	FU_COSWID_LINK_REL_SEE_ALSO = 9,
	FU_COSWID_LINK_REL_SUPERSEDES = 10,
	FU_COSWID_LINK_REL_SUPPLEMENTAL = 11,
} FuCoswidLinkRel;

typedef enum {
	FU_COSWID_ENTITY_ROLE_UNKNOWN,
	FU_COSWID_ENTITY_ROLE_TAG_CREATOR,
	FU_COSWID_ENTITY_ROLE_SOFTWARE_CREATOR,
	FU_COSWID_ENTITY_ROLE_AGGREGATOR,
	FU_COSWID_ENTITY_ROLE_DISTRIBUTOR,
	FU_COSWID_ENTITY_ROLE_LICENSOR,
	FU_COSWID_ENTITY_ROLE_MAINTAINER,
} FuCoswidEntityRole;

FuCoswidEntityRole
fu_coswid_entity_role_from_string(const gchar *val);
const gchar *
fu_coswid_entity_role_to_string(FuCoswidEntityRole val);
FuCoswidLinkRel
fu_coswid_link_rel_from_string(const gchar *val);
const gchar *
fu_coswid_link_rel_to_string(FuCoswidLinkRel val);
FuCoswidVersionScheme
fu_coswid_version_scheme_from_string(const gchar *val);
const gchar *
fu_coswid_version_scheme_to_string(FuCoswidVersionScheme val);
