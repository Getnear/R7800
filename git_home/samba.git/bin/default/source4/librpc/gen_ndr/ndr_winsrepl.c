/* parser auto-generated by pidl */

#include "includes.h"
#include "bin/default/source4/librpc/gen_ndr/ndr_winsrepl.h"

#include "librpc/gen_ndr/ndr_nbt.h"
static enum ndr_err_code ndr_push_wrepl_ip(struct ndr_push *ndr, int ndr_flags, const struct wrepl_ip *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->owner));
			NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->ip));
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_ip(struct ndr_pull *ndr, int ndr_flags, struct wrepl_ip *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->owner));
			NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->ip));
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_ip(struct ndr_print *ndr, const char *name, const struct wrepl_ip *r)
{
	ndr_print_struct(ndr, name, "wrepl_ip");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		ndr->depth++;
		ndr_print_ipv4address(ndr, "owner", r->owner);
		ndr_print_ipv4address(ndr, "ip", r->ip);
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

static enum ndr_err_code ndr_push_wrepl_address_list(struct ndr_push *ndr, int ndr_flags, const struct wrepl_address_list *r)
{
	uint32_t cntr_ips_0;
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_LITTLE_ENDIAN);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_ips));
			for (cntr_ips_0 = 0; cntr_ips_0 < (r->num_ips); cntr_ips_0++) {
				NDR_CHECK(ndr_push_wrepl_ip(ndr, NDR_SCALARS, &r->ips[cntr_ips_0]));
			}
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_address_list(struct ndr_pull *ndr, int ndr_flags, struct wrepl_address_list *r)
{
	uint32_t size_ips_0 = 0;
	uint32_t cntr_ips_0;
	TALLOC_CTX *_mem_save_ips_0 = NULL;
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_LITTLE_ENDIAN);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_ips));
			size_ips_0 = r->num_ips;
			NDR_PULL_ALLOC_N(ndr, r->ips, size_ips_0);
			_mem_save_ips_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->ips, 0);
			for (cntr_ips_0 = 0; cntr_ips_0 < (size_ips_0); cntr_ips_0++) {
				NDR_CHECK(ndr_pull_wrepl_ip(ndr, NDR_SCALARS, &r->ips[cntr_ips_0]));
			}
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_ips_0, 0);
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_address_list(struct ndr_print *ndr, const char *name, const struct wrepl_address_list *r)
{
	uint32_t cntr_ips_0;
	ndr_print_struct(ndr, name, "wrepl_address_list");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_LITTLE_ENDIAN);
		ndr->depth++;
		ndr_print_uint32(ndr, "num_ips", r->num_ips);
		ndr->print(ndr, "%s: ARRAY(%d)", "ips", (int)r->num_ips);
		ndr->depth++;
		for (cntr_ips_0 = 0; cntr_ips_0 < (r->num_ips); cntr_ips_0++) {
			ndr_print_wrepl_ip(ndr, "ips", &r->ips[cntr_ips_0]);
		}
		ndr->depth--;
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

static enum ndr_err_code ndr_push_wrepl_addresses(struct ndr_push *ndr, int ndr_flags, const union wrepl_addresses *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		NDR_CHECK(ndr_push_union_align(ndr, 4));
		switch (level) {
			case 0: {
				NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->ip));
			break; }

			case 2: {
				NDR_CHECK(ndr_push_wrepl_address_list(ndr, NDR_SCALARS, &r->addresses));
			break; }

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		switch (level) {
			case 0:
			break;

			case 2:
			break;

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_addresses(struct ndr_pull *ndr, int ndr_flags, union wrepl_addresses *r)
{
	uint32_t level;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		level = ndr_pull_get_switch_value(ndr, r);
		NDR_CHECK(ndr_pull_union_align(ndr, 4));
		switch (level) {
			case 0: {
				NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->ip));
			break; }

			case 2: {
				NDR_CHECK(ndr_pull_wrepl_address_list(ndr, NDR_SCALARS, &r->addresses));
			break; }

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		/* The token is not needed after this. */
		level = ndr_pull_steal_switch_value(ndr, r);
		switch (level) {
			case 0:
			break;

			case 2:
			break;

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_addresses(struct ndr_print *ndr, const char *name, const union wrepl_addresses *r)
{
	uint32_t level;
	level = ndr_print_get_switch_value(ndr, r);
	ndr_print_union(ndr, name, level, "wrepl_addresses");
	switch (level) {
		case 0:
			ndr_print_ipv4address(ndr, "ip", r->ip);
		break;

		case 2:
			ndr_print_wrepl_address_list(ndr, "addresses", &r->addresses);
		break;

		default:
			ndr_print_bad_level(ndr, name, level);
	}
}

static enum ndr_err_code ndr_push_wrepl_flags(struct ndr_push *ndr, int ndr_flags, uint32_t r)
{
	NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_flags(struct ndr_pull *ndr, int ndr_flags, uint32_t *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_flags(struct ndr_print *ndr, const char *name, uint32_t r)
{
	ndr_print_uint32(ndr, name, r);
	ndr->depth++;
	ndr_print_bitmap_flag(ndr, sizeof(uint32_t), "WREPL_FLAGS_RECORD_TYPE", WREPL_FLAGS_RECORD_TYPE, r);
	ndr_print_bitmap_flag(ndr, sizeof(uint32_t), "WREPL_FLAGS_RECORD_STATE", WREPL_FLAGS_RECORD_STATE, r);
	ndr_print_bitmap_flag(ndr, sizeof(uint32_t), "WREPL_FLAGS_REGISTERED_LOCAL", WREPL_FLAGS_REGISTERED_LOCAL, r);
	ndr_print_bitmap_flag(ndr, sizeof(uint32_t), "WREPL_FLAGS_NODE_TYPE", WREPL_FLAGS_NODE_TYPE, r);
	ndr_print_bitmap_flag(ndr, sizeof(uint32_t), "WREPL_FLAGS_IS_STATIC", WREPL_FLAGS_IS_STATIC, r);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_group_flag(struct ndr_push *ndr, int ndr_flags, enum wrepl_group_flag r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_group_flag(struct ndr_pull *ndr, int ndr_flags, enum wrepl_group_flag *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_group_flag(struct ndr_print *ndr, const char *name, enum wrepl_group_flag r)
{
	const char *val = NULL;

	switch (r) {
		case WREPL_GROUP_FLAG_NO_GROUP: val = "WREPL_GROUP_FLAG_NO_GROUP"; break;
		case WREPL_GROUP_FLAG_IS_GROUP: val = "WREPL_GROUP_FLAG_IS_GROUP"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_wrepl_wins_name(struct ndr_push *ndr, int ndr_flags, const struct wrepl_wins_name *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_wrepl_nbt_name(ndr, NDR_SCALARS, r->name));
		NDR_CHECK(ndr_push_wrepl_flags(ndr, NDR_SCALARS, r->flags));
		{
			uint32_t _flags_save_wrepl_group_flag = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_LITTLE_ENDIAN);
			NDR_CHECK(ndr_push_wrepl_group_flag(ndr, NDR_SCALARS, (((((r->flags) & WREPL_FLAGS_RECORD_TYPE) == WREPL_TYPE_GROUP) || (((r->flags) & WREPL_FLAGS_RECORD_TYPE) == WREPL_TYPE_SGROUP))?WREPL_GROUP_FLAG_IS_GROUP:WREPL_GROUP_FLAG_NO_GROUP)));
			ndr->flags = _flags_save_wrepl_group_flag;
		}
		NDR_CHECK(ndr_push_udlongr(ndr, NDR_SCALARS, r->id));
		NDR_CHECK(ndr_push_set_switch_value(ndr, &r->addresses, r->flags & 2));
		NDR_CHECK(ndr_push_wrepl_addresses(ndr, NDR_SCALARS, &r->addresses));
		NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->unknown));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_wins_name(struct ndr_pull *ndr, int ndr_flags, struct wrepl_wins_name *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_wrepl_nbt_name(ndr, NDR_SCALARS, &r->name));
		NDR_CHECK(ndr_pull_wrepl_flags(ndr, NDR_SCALARS, &r->flags));
		{
			uint32_t _flags_save_wrepl_group_flag = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_LITTLE_ENDIAN);
			NDR_CHECK(ndr_pull_wrepl_group_flag(ndr, NDR_SCALARS, &r->is_group));
			ndr->flags = _flags_save_wrepl_group_flag;
		}
		NDR_CHECK(ndr_pull_udlongr(ndr, NDR_SCALARS, &r->id));
		NDR_CHECK(ndr_pull_set_switch_value(ndr, &r->addresses, r->flags & 2));
		NDR_CHECK(ndr_pull_wrepl_addresses(ndr, NDR_SCALARS, &r->addresses));
		NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->unknown));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_wins_name(struct ndr_print *ndr, const char *name, const struct wrepl_wins_name *r)
{
	ndr_print_struct(ndr, name, "wrepl_wins_name");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_wrepl_nbt_name(ndr, "name", r->name);
	ndr_print_wrepl_flags(ndr, "flags", r->flags);
	ndr_print_wrepl_group_flag(ndr, "is_group", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?(((((r->flags) & WREPL_FLAGS_RECORD_TYPE) == WREPL_TYPE_GROUP) || (((r->flags) & WREPL_FLAGS_RECORD_TYPE) == WREPL_TYPE_SGROUP))?WREPL_GROUP_FLAG_IS_GROUP:WREPL_GROUP_FLAG_NO_GROUP):r->is_group);
	ndr_print_udlongr(ndr, "id", r->id);
	ndr_print_set_switch_value(ndr, &r->addresses, r->flags & 2);
	ndr_print_wrepl_addresses(ndr, "addresses", &r->addresses);
	ndr_print_ipv4address(ndr, "unknown", r->unknown);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_send_reply(struct ndr_push *ndr, int ndr_flags, const struct wrepl_send_reply *r)
{
	uint32_t cntr_names_0;
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_names));
		for (cntr_names_0 = 0; cntr_names_0 < (r->num_names); cntr_names_0++) {
			NDR_CHECK(ndr_push_wrepl_wins_name(ndr, NDR_SCALARS, &r->names[cntr_names_0]));
		}
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_send_reply(struct ndr_pull *ndr, int ndr_flags, struct wrepl_send_reply *r)
{
	uint32_t size_names_0 = 0;
	uint32_t cntr_names_0;
	TALLOC_CTX *_mem_save_names_0 = NULL;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_names));
		size_names_0 = r->num_names;
		NDR_PULL_ALLOC_N(ndr, r->names, size_names_0);
		_mem_save_names_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->names, 0);
		for (cntr_names_0 = 0; cntr_names_0 < (size_names_0); cntr_names_0++) {
			NDR_CHECK(ndr_pull_wrepl_wins_name(ndr, NDR_SCALARS, &r->names[cntr_names_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_names_0, 0);
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_send_reply(struct ndr_print *ndr, const char *name, const struct wrepl_send_reply *r)
{
	uint32_t cntr_names_0;
	ndr_print_struct(ndr, name, "wrepl_send_reply");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint32(ndr, "num_names", r->num_names);
	ndr->print(ndr, "%s: ARRAY(%d)", "names", (int)r->num_names);
	ndr->depth++;
	for (cntr_names_0 = 0; cntr_names_0 < (r->num_names); cntr_names_0++) {
		ndr_print_wrepl_wins_name(ndr, "names", &r->names[cntr_names_0]);
	}
	ndr->depth--;
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_wins_owner(struct ndr_push *ndr, int ndr_flags, const struct wrepl_wins_owner *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->address));
		NDR_CHECK(ndr_push_udlongr(ndr, NDR_SCALARS, r->max_version));
		NDR_CHECK(ndr_push_udlongr(ndr, NDR_SCALARS, r->min_version));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->type));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_wins_owner(struct ndr_pull *ndr, int ndr_flags, struct wrepl_wins_owner *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->address));
		NDR_CHECK(ndr_pull_udlongr(ndr, NDR_SCALARS, &r->max_version));
		NDR_CHECK(ndr_pull_udlongr(ndr, NDR_SCALARS, &r->min_version));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->type));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_wins_owner(struct ndr_print *ndr, const char *name, const struct wrepl_wins_owner *r)
{
	ndr_print_struct(ndr, name, "wrepl_wins_owner");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_ipv4address(ndr, "address", r->address);
	ndr_print_udlongr(ndr, "max_version", r->max_version);
	ndr_print_udlongr(ndr, "min_version", r->min_version);
	ndr_print_uint32(ndr, "type", r->type);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_table(struct ndr_push *ndr, int ndr_flags, const struct wrepl_table *r)
{
	uint32_t cntr_partners_0;
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->partner_count));
		for (cntr_partners_0 = 0; cntr_partners_0 < (r->partner_count); cntr_partners_0++) {
			NDR_CHECK(ndr_push_wrepl_wins_owner(ndr, NDR_SCALARS, &r->partners[cntr_partners_0]));
		}
		NDR_CHECK(ndr_push_ipv4address(ndr, NDR_SCALARS, r->initiator));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_table(struct ndr_pull *ndr, int ndr_flags, struct wrepl_table *r)
{
	uint32_t size_partners_0 = 0;
	uint32_t cntr_partners_0;
	TALLOC_CTX *_mem_save_partners_0 = NULL;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->partner_count));
		size_partners_0 = r->partner_count;
		NDR_PULL_ALLOC_N(ndr, r->partners, size_partners_0);
		_mem_save_partners_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->partners, 0);
		for (cntr_partners_0 = 0; cntr_partners_0 < (size_partners_0); cntr_partners_0++) {
			NDR_CHECK(ndr_pull_wrepl_wins_owner(ndr, NDR_SCALARS, &r->partners[cntr_partners_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_partners_0, 0);
		NDR_CHECK(ndr_pull_ipv4address(ndr, NDR_SCALARS, &r->initiator));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_table(struct ndr_print *ndr, const char *name, const struct wrepl_table *r)
{
	uint32_t cntr_partners_0;
	ndr_print_struct(ndr, name, "wrepl_table");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint32(ndr, "partner_count", r->partner_count);
	ndr->print(ndr, "%s: ARRAY(%d)", "partners", (int)r->partner_count);
	ndr->depth++;
	for (cntr_partners_0 = 0; cntr_partners_0 < (r->partner_count); cntr_partners_0++) {
		ndr_print_wrepl_wins_owner(ndr, "partners", &r->partners[cntr_partners_0]);
	}
	ndr->depth--;
	ndr_print_ipv4address(ndr, "initiator", r->initiator);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_replication_cmd(struct ndr_push *ndr, int ndr_flags, enum wrepl_replication_cmd r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_replication_cmd(struct ndr_pull *ndr, int ndr_flags, enum wrepl_replication_cmd *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_replication_cmd(struct ndr_print *ndr, const char *name, enum wrepl_replication_cmd r)
{
	const char *val = NULL;

	switch (r) {
		case WREPL_REPL_TABLE_QUERY: val = "WREPL_REPL_TABLE_QUERY"; break;
		case WREPL_REPL_TABLE_REPLY: val = "WREPL_REPL_TABLE_REPLY"; break;
		case WREPL_REPL_SEND_REQUEST: val = "WREPL_REPL_SEND_REQUEST"; break;
		case WREPL_REPL_SEND_REPLY: val = "WREPL_REPL_SEND_REPLY"; break;
		case WREPL_REPL_UPDATE: val = "WREPL_REPL_UPDATE"; break;
		case WREPL_REPL_UPDATE2: val = "WREPL_REPL_UPDATE2"; break;
		case WREPL_REPL_INFORM: val = "WREPL_REPL_INFORM"; break;
		case WREPL_REPL_INFORM2: val = "WREPL_REPL_INFORM2"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_wrepl_replication_info(struct ndr_push *ndr, int ndr_flags, const union wrepl_replication_info *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		NDR_CHECK(ndr_push_union_align(ndr, 4));
		switch (level) {
			case WREPL_REPL_TABLE_QUERY: {
			break; }

			case WREPL_REPL_TABLE_REPLY: {
				NDR_CHECK(ndr_push_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_SEND_REQUEST: {
				NDR_CHECK(ndr_push_wrepl_wins_owner(ndr, NDR_SCALARS, &r->owner));
			break; }

			case WREPL_REPL_SEND_REPLY: {
				NDR_CHECK(ndr_push_wrepl_send_reply(ndr, NDR_SCALARS, &r->reply));
			break; }

			case WREPL_REPL_UPDATE: {
				NDR_CHECK(ndr_push_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_UPDATE2: {
				NDR_CHECK(ndr_push_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_INFORM: {
				NDR_CHECK(ndr_push_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_INFORM2: {
				NDR_CHECK(ndr_push_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		switch (level) {
			case WREPL_REPL_TABLE_QUERY:
			break;

			case WREPL_REPL_TABLE_REPLY:
			break;

			case WREPL_REPL_SEND_REQUEST:
			break;

			case WREPL_REPL_SEND_REPLY:
			break;

			case WREPL_REPL_UPDATE:
			break;

			case WREPL_REPL_UPDATE2:
			break;

			case WREPL_REPL_INFORM:
			break;

			case WREPL_REPL_INFORM2:
			break;

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_replication_info(struct ndr_pull *ndr, int ndr_flags, union wrepl_replication_info *r)
{
	uint32_t level;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		level = ndr_pull_get_switch_value(ndr, r);
		NDR_CHECK(ndr_pull_union_align(ndr, 4));
		switch (level) {
			case WREPL_REPL_TABLE_QUERY: {
			break; }

			case WREPL_REPL_TABLE_REPLY: {
				NDR_CHECK(ndr_pull_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_SEND_REQUEST: {
				NDR_CHECK(ndr_pull_wrepl_wins_owner(ndr, NDR_SCALARS, &r->owner));
			break; }

			case WREPL_REPL_SEND_REPLY: {
				NDR_CHECK(ndr_pull_wrepl_send_reply(ndr, NDR_SCALARS, &r->reply));
			break; }

			case WREPL_REPL_UPDATE: {
				NDR_CHECK(ndr_pull_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_UPDATE2: {
				NDR_CHECK(ndr_pull_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_INFORM: {
				NDR_CHECK(ndr_pull_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			case WREPL_REPL_INFORM2: {
				NDR_CHECK(ndr_pull_wrepl_table(ndr, NDR_SCALARS, &r->table));
			break; }

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		/* The token is not needed after this. */
		level = ndr_pull_steal_switch_value(ndr, r);
		switch (level) {
			case WREPL_REPL_TABLE_QUERY:
			break;

			case WREPL_REPL_TABLE_REPLY:
			break;

			case WREPL_REPL_SEND_REQUEST:
			break;

			case WREPL_REPL_SEND_REPLY:
			break;

			case WREPL_REPL_UPDATE:
			break;

			case WREPL_REPL_UPDATE2:
			break;

			case WREPL_REPL_INFORM:
			break;

			case WREPL_REPL_INFORM2:
			break;

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_replication_info(struct ndr_print *ndr, const char *name, const union wrepl_replication_info *r)
{
	uint32_t level;
	level = ndr_print_get_switch_value(ndr, r);
	ndr_print_union(ndr, name, level, "wrepl_replication_info");
	switch (level) {
		case WREPL_REPL_TABLE_QUERY:
		break;

		case WREPL_REPL_TABLE_REPLY:
			ndr_print_wrepl_table(ndr, "table", &r->table);
		break;

		case WREPL_REPL_SEND_REQUEST:
			ndr_print_wrepl_wins_owner(ndr, "owner", &r->owner);
		break;

		case WREPL_REPL_SEND_REPLY:
			ndr_print_wrepl_send_reply(ndr, "reply", &r->reply);
		break;

		case WREPL_REPL_UPDATE:
			ndr_print_wrepl_table(ndr, "table", &r->table);
		break;

		case WREPL_REPL_UPDATE2:
			ndr_print_wrepl_table(ndr, "table", &r->table);
		break;

		case WREPL_REPL_INFORM:
			ndr_print_wrepl_table(ndr, "table", &r->table);
		break;

		case WREPL_REPL_INFORM2:
			ndr_print_wrepl_table(ndr, "table", &r->table);
		break;

		default:
			ndr_print_bad_level(ndr, name, level);
	}
}

static enum ndr_err_code ndr_push_wrepl_replication(struct ndr_push *ndr, int ndr_flags, const struct wrepl_replication *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_wrepl_replication_cmd(ndr, NDR_SCALARS, r->command));
		NDR_CHECK(ndr_push_set_switch_value(ndr, &r->info, r->command));
		NDR_CHECK(ndr_push_wrepl_replication_info(ndr, NDR_SCALARS, &r->info));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_push_wrepl_replication_info(ndr, NDR_BUFFERS, &r->info));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_replication(struct ndr_pull *ndr, int ndr_flags, struct wrepl_replication *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_wrepl_replication_cmd(ndr, NDR_SCALARS, &r->command));
		NDR_CHECK(ndr_pull_set_switch_value(ndr, &r->info, r->command));
		NDR_CHECK(ndr_pull_wrepl_replication_info(ndr, NDR_SCALARS, &r->info));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_pull_wrepl_replication_info(ndr, NDR_BUFFERS, &r->info));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_replication(struct ndr_print *ndr, const char *name, const struct wrepl_replication *r)
{
	ndr_print_struct(ndr, name, "wrepl_replication");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_wrepl_replication_cmd(ndr, "command", r->command);
	ndr_print_set_switch_value(ndr, &r->info, r->command);
	ndr_print_wrepl_replication_info(ndr, "info", &r->info);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_start(struct ndr_push *ndr, int ndr_flags, const struct wrepl_start *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->assoc_ctx));
		NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, r->minor_version));
		NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, r->major_version));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_start(struct ndr_pull *ndr, int ndr_flags, struct wrepl_start *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->assoc_ctx));
		NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->minor_version));
		NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->major_version));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_start(struct ndr_print *ndr, const char *name, const struct wrepl_start *r)
{
	ndr_print_struct(ndr, name, "wrepl_start");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint32(ndr, "assoc_ctx", r->assoc_ctx);
	ndr_print_uint16(ndr, "minor_version", r->minor_version);
	ndr_print_uint16(ndr, "major_version", r->major_version);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_stop(struct ndr_push *ndr, int ndr_flags, const struct wrepl_stop *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->reason));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_stop(struct ndr_pull *ndr, int ndr_flags, struct wrepl_stop *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->reason));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_stop(struct ndr_print *ndr, const char *name, const struct wrepl_stop *r)
{
	ndr_print_struct(ndr, name, "wrepl_stop");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint32(ndr, "reason", r->reason);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_wrepl_mess_type(struct ndr_push *ndr, int ndr_flags, enum wrepl_mess_type r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_mess_type(struct ndr_pull *ndr, int ndr_flags, enum wrepl_mess_type *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_mess_type(struct ndr_print *ndr, const char *name, enum wrepl_mess_type r)
{
	const char *val = NULL;

	switch (r) {
		case WREPL_START_ASSOCIATION: val = "WREPL_START_ASSOCIATION"; break;
		case WREPL_START_ASSOCIATION_REPLY: val = "WREPL_START_ASSOCIATION_REPLY"; break;
		case WREPL_STOP_ASSOCIATION: val = "WREPL_STOP_ASSOCIATION"; break;
		case WREPL_REPLICATION: val = "WREPL_REPLICATION"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_wrepl_message(struct ndr_push *ndr, int ndr_flags, const union wrepl_message *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		NDR_CHECK(ndr_push_union_align(ndr, 4));
		switch (level) {
			case WREPL_START_ASSOCIATION: {
				NDR_CHECK(ndr_push_wrepl_start(ndr, NDR_SCALARS, &r->start));
			break; }

			case WREPL_START_ASSOCIATION_REPLY: {
				NDR_CHECK(ndr_push_wrepl_start(ndr, NDR_SCALARS, &r->start_reply));
			break; }

			case WREPL_STOP_ASSOCIATION: {
				NDR_CHECK(ndr_push_wrepl_stop(ndr, NDR_SCALARS, &r->stop));
			break; }

			case WREPL_REPLICATION: {
				NDR_CHECK(ndr_push_wrepl_replication(ndr, NDR_SCALARS, &r->replication));
			break; }

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		uint32_t level = ndr_push_get_switch_value(ndr, r);
		switch (level) {
			case WREPL_START_ASSOCIATION:
			break;

			case WREPL_START_ASSOCIATION_REPLY:
			break;

			case WREPL_STOP_ASSOCIATION:
			break;

			case WREPL_REPLICATION:
				NDR_CHECK(ndr_push_wrepl_replication(ndr, NDR_BUFFERS, &r->replication));
			break;

			default:
				return ndr_push_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_wrepl_message(struct ndr_pull *ndr, int ndr_flags, union wrepl_message *r)
{
	uint32_t level;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		level = ndr_pull_get_switch_value(ndr, r);
		NDR_CHECK(ndr_pull_union_align(ndr, 4));
		switch (level) {
			case WREPL_START_ASSOCIATION: {
				NDR_CHECK(ndr_pull_wrepl_start(ndr, NDR_SCALARS, &r->start));
			break; }

			case WREPL_START_ASSOCIATION_REPLY: {
				NDR_CHECK(ndr_pull_wrepl_start(ndr, NDR_SCALARS, &r->start_reply));
			break; }

			case WREPL_STOP_ASSOCIATION: {
				NDR_CHECK(ndr_pull_wrepl_stop(ndr, NDR_SCALARS, &r->stop));
			break; }

			case WREPL_REPLICATION: {
				NDR_CHECK(ndr_pull_wrepl_replication(ndr, NDR_SCALARS, &r->replication));
			break; }

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		/* The token is not needed after this. */
		level = ndr_pull_steal_switch_value(ndr, r);
		switch (level) {
			case WREPL_START_ASSOCIATION:
			break;

			case WREPL_START_ASSOCIATION_REPLY:
			break;

			case WREPL_STOP_ASSOCIATION:
			break;

			case WREPL_REPLICATION:
				NDR_CHECK(ndr_pull_wrepl_replication(ndr, NDR_BUFFERS, &r->replication));
			break;

			default:
				return ndr_pull_error(ndr, NDR_ERR_BAD_SWITCH, "Bad switch value %u at %s", level, __location__);
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_message(struct ndr_print *ndr, const char *name, const union wrepl_message *r)
{
	uint32_t level;
	level = ndr_print_get_switch_value(ndr, r);
	ndr_print_union(ndr, name, level, "wrepl_message");
	switch (level) {
		case WREPL_START_ASSOCIATION:
			ndr_print_wrepl_start(ndr, "start", &r->start);
		break;

		case WREPL_START_ASSOCIATION_REPLY:
			ndr_print_wrepl_start(ndr, "start_reply", &r->start_reply);
		break;

		case WREPL_STOP_ASSOCIATION:
			ndr_print_wrepl_stop(ndr, "stop", &r->stop);
		break;

		case WREPL_REPLICATION:
			ndr_print_wrepl_replication(ndr, "replication", &r->replication);
		break;

		default:
			ndr_print_bad_level(ndr, name, level);
	}
}

_PUBLIC_ enum ndr_err_code ndr_push_wrepl_packet(struct ndr_push *ndr, int ndr_flags, const struct wrepl_packet *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->opcode));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->assoc_ctx));
			NDR_CHECK(ndr_push_wrepl_mess_type(ndr, NDR_SCALARS, r->mess_type));
			NDR_CHECK(ndr_push_set_switch_value(ndr, &r->message, r->mess_type));
			NDR_CHECK(ndr_push_wrepl_message(ndr, NDR_SCALARS, &r->message));
			{
				uint32_t _flags_save_DATA_BLOB = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_REMAINING);
				NDR_CHECK(ndr_push_DATA_BLOB(ndr, NDR_SCALARS, r->padding));
				ndr->flags = _flags_save_DATA_BLOB;
			}
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
			NDR_CHECK(ndr_push_wrepl_message(ndr, NDR_BUFFERS, &r->message));
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_wrepl_packet(struct ndr_pull *ndr, int ndr_flags, struct wrepl_packet *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->opcode));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->assoc_ctx));
			NDR_CHECK(ndr_pull_wrepl_mess_type(ndr, NDR_SCALARS, &r->mess_type));
			NDR_CHECK(ndr_pull_set_switch_value(ndr, &r->message, r->mess_type));
			NDR_CHECK(ndr_pull_wrepl_message(ndr, NDR_SCALARS, &r->message));
			{
				uint32_t _flags_save_DATA_BLOB = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_REMAINING);
				NDR_CHECK(ndr_pull_DATA_BLOB(ndr, NDR_SCALARS, &r->padding));
				ndr->flags = _flags_save_DATA_BLOB;
			}
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
			NDR_CHECK(ndr_pull_wrepl_message(ndr, NDR_BUFFERS, &r->message));
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_packet(struct ndr_print *ndr, const char *name, const struct wrepl_packet *r)
{
	ndr_print_struct(ndr, name, "wrepl_packet");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		ndr->depth++;
		ndr_print_uint32(ndr, "opcode", r->opcode);
		ndr_print_uint32(ndr, "assoc_ctx", r->assoc_ctx);
		ndr_print_wrepl_mess_type(ndr, "mess_type", r->mess_type);
		ndr_print_set_switch_value(ndr, &r->message, r->mess_type);
		ndr_print_wrepl_message(ndr, "message", &r->message);
		ndr_print_DATA_BLOB(ndr, "padding", r->padding);
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

_PUBLIC_ size_t ndr_size_wrepl_packet(const struct wrepl_packet *r, int flags)
{
	flags |= LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX;
	return ndr_size_struct(r, flags, (ndr_push_flags_fn_t)ndr_push_wrepl_packet);
}

_PUBLIC_ enum ndr_err_code ndr_push_wrepl_wrap(struct ndr_push *ndr, int ndr_flags, const struct wrepl_wrap *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, ndr_size_wrepl_packet(&r->packet, ndr->flags)));
			NDR_CHECK(ndr_push_wrepl_packet(ndr, NDR_SCALARS, &r->packet));
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
			NDR_CHECK(ndr_push_wrepl_packet(ndr, NDR_BUFFERS, &r->packet));
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_wrepl_wrap(struct ndr_pull *ndr, int ndr_flags, struct wrepl_wrap *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->size));
			NDR_CHECK(ndr_pull_wrepl_packet(ndr, NDR_SCALARS, &r->packet));
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
			NDR_CHECK(ndr_pull_wrepl_packet(ndr, NDR_BUFFERS, &r->packet));
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_wrepl_wrap(struct ndr_print *ndr, const char *name, const struct wrepl_wrap *r)
{
	ndr_print_struct(ndr, name, "wrepl_wrap");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN|LIBNDR_PRINT_ARRAY_HEX);
		ndr->depth++;
		ndr_print_uint32(ndr, "size", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?ndr_size_wrepl_packet(&r->packet, ndr->flags):r->size);
		ndr_print_wrepl_packet(ndr, "packet", &r->packet);
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

static enum ndr_err_code ndr_push_decode_winsrepl(struct ndr_push *ndr, int flags, const struct decode_winsrepl *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_wrepl_wrap(ndr, NDR_SCALARS|NDR_BUFFERS, &r->in.p));
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_decode_winsrepl(struct ndr_pull *ndr, int flags, struct decode_winsrepl *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_wrepl_wrap(ndr, NDR_SCALARS|NDR_BUFFERS, &r->in.p));
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_decode_winsrepl(struct ndr_print *ndr, const char *name, int flags, const struct decode_winsrepl *r)
{
	ndr_print_struct(ndr, name, "decode_winsrepl");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "decode_winsrepl");
		ndr->depth++;
		ndr_print_wrepl_wrap(ndr, "p", &r->in.p);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "decode_winsrepl");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static const struct ndr_interface_call wrepl_calls[] = {
	{
		"decode_winsrepl",
		sizeof(struct decode_winsrepl),
		(ndr_push_flags_fn_t) ndr_push_decode_winsrepl,
		(ndr_pull_flags_fn_t) ndr_pull_decode_winsrepl,
		(ndr_print_function_t) ndr_print_decode_winsrepl,
		{ 0, NULL },
		{ 0, NULL },
	},
	{ NULL, 0, NULL, NULL, NULL }
};

static const char * const wrepl_endpoint_strings[] = {
	"ncacn_np:[\\pipe\\wrepl]", 
};

static const struct ndr_interface_string_array wrepl_endpoints = {
	.count	= 1,
	.names	= wrepl_endpoint_strings
};

static const char * const wrepl_authservice_strings[] = {
	"host", 
};

static const struct ndr_interface_string_array wrepl_authservices = {
	.count	= 1,
	.names	= wrepl_authservice_strings
};


const struct ndr_interface_table ndr_table_wrepl = {
	.name		= "wrepl",
	.syntax_id	= {
		{0x915f5653,0xbac1,0x431c,{0x97,0xee},{0x9f,0xfb,0x34,0x52,0x69,0x21}},
		NDR_WREPL_VERSION
	},
	.helpstring	= NDR_WREPL_HELPSTRING,
	.num_calls	= 1,
	.calls		= wrepl_calls,
	.endpoints	= &wrepl_endpoints,
	.authservices	= &wrepl_authservices
};

