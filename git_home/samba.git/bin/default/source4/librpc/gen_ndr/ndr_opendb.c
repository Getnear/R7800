/* parser auto-generated by pidl */

#include "includes.h"
#include "bin/default/source4/librpc/gen_ndr/ndr_opendb.h"

#include "librpc/gen_ndr/ndr_server_id.h"
static enum ndr_err_code ndr_push_opendb_entry(struct ndr_push *ndr, int ndr_flags, const struct opendb_entry *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->stream_id));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->share_access));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->access_mask));
		NDR_CHECK(ndr_push_pointer(ndr, NDR_SCALARS, r->file_handle));
		NDR_CHECK(ndr_push_pointer(ndr, NDR_SCALARS, r->fd));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->delete_on_close));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->allow_level_II_oplock));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->oplock_level));
		NDR_CHECK(ndr_push_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_opendb_entry(struct ndr_pull *ndr, int ndr_flags, struct opendb_entry *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->stream_id));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->share_access));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->access_mask));
		NDR_CHECK(ndr_pull_pointer(ndr, NDR_SCALARS, &r->file_handle));
		NDR_CHECK(ndr_pull_pointer(ndr, NDR_SCALARS, &r->fd));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->delete_on_close));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->allow_level_II_oplock));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->oplock_level));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_opendb_entry(struct ndr_print *ndr, const char *name, const struct opendb_entry *r)
{
	ndr_print_struct(ndr, name, "opendb_entry");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_server_id(ndr, "server", &r->server);
	ndr_print_uint32(ndr, "stream_id", r->stream_id);
	ndr_print_uint32(ndr, "share_access", r->share_access);
	ndr_print_uint32(ndr, "access_mask", r->access_mask);
	ndr_print_pointer(ndr, "file_handle", r->file_handle);
	ndr_print_pointer(ndr, "fd", r->fd);
	ndr_print_uint8(ndr, "delete_on_close", r->delete_on_close);
	ndr_print_uint8(ndr, "allow_level_II_oplock", r->allow_level_II_oplock);
	ndr_print_uint32(ndr, "oplock_level", r->oplock_level);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_opendb_pending(struct ndr_push *ndr, int ndr_flags, const struct opendb_pending *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_push_pointer(ndr, NDR_SCALARS, r->notify_ptr));
		NDR_CHECK(ndr_push_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_opendb_pending(struct ndr_pull *ndr, int ndr_flags, struct opendb_pending *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_pull_pointer(ndr, NDR_SCALARS, &r->notify_ptr));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_opendb_pending(struct ndr_print *ndr, const char *name, const struct opendb_pending *r)
{
	ndr_print_struct(ndr, name, "opendb_pending");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_server_id(ndr, "server", &r->server);
	ndr_print_pointer(ndr, "notify_ptr", r->notify_ptr);
	ndr->depth--;
}

_PUBLIC_ enum ndr_err_code ndr_push_opendb_file(struct ndr_push *ndr, int ndr_flags, const struct opendb_file *r)
{
	uint32_t cntr_entries_0;
	uint32_t cntr_pending_0;
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->delete_on_close));
		NDR_CHECK(ndr_push_NTTIME(ndr, NDR_SCALARS, r->open_write_time));
		NDR_CHECK(ndr_push_NTTIME(ndr, NDR_SCALARS, r->changed_write_time));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_push_string(ndr, NDR_SCALARS, r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_entries));
		for (cntr_entries_0 = 0; cntr_entries_0 < (r->num_entries); cntr_entries_0++) {
			NDR_CHECK(ndr_push_opendb_entry(ndr, NDR_SCALARS, &r->entries[cntr_entries_0]));
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_pending));
		for (cntr_pending_0 = 0; cntr_pending_0 < (r->num_pending); cntr_pending_0++) {
			NDR_CHECK(ndr_push_opendb_pending(ndr, NDR_SCALARS, &r->pending[cntr_pending_0]));
		}
		NDR_CHECK(ndr_push_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_opendb_file(struct ndr_pull *ndr, int ndr_flags, struct opendb_file *r)
{
	uint32_t size_entries_0 = 0;
	uint32_t cntr_entries_0;
	TALLOC_CTX *_mem_save_entries_0 = NULL;
	uint32_t size_pending_0 = 0;
	uint32_t cntr_pending_0;
	TALLOC_CTX *_mem_save_pending_0 = NULL;
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->delete_on_close));
		NDR_CHECK(ndr_pull_NTTIME(ndr, NDR_SCALARS, &r->open_write_time));
		NDR_CHECK(ndr_pull_NTTIME(ndr, NDR_SCALARS, &r->changed_write_time));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_pull_string(ndr, NDR_SCALARS, &r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_entries));
		size_entries_0 = r->num_entries;
		NDR_PULL_ALLOC_N(ndr, r->entries, size_entries_0);
		_mem_save_entries_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->entries, 0);
		for (cntr_entries_0 = 0; cntr_entries_0 < (size_entries_0); cntr_entries_0++) {
			NDR_CHECK(ndr_pull_opendb_entry(ndr, NDR_SCALARS, &r->entries[cntr_entries_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_entries_0, 0);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_pending));
		size_pending_0 = r->num_pending;
		NDR_PULL_ALLOC_N(ndr, r->pending, size_pending_0);
		_mem_save_pending_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->pending, 0);
		for (cntr_pending_0 = 0; cntr_pending_0 < (size_pending_0); cntr_pending_0++) {
			NDR_CHECK(ndr_pull_opendb_pending(ndr, NDR_SCALARS, &r->pending[cntr_pending_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_pending_0, 0);
		NDR_CHECK(ndr_pull_trailer_align(ndr, 8));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_opendb_file(struct ndr_print *ndr, const char *name, const struct opendb_file *r)
{
	uint32_t cntr_entries_0;
	uint32_t cntr_pending_0;
	ndr_print_struct(ndr, name, "opendb_file");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint8(ndr, "delete_on_close", r->delete_on_close);
	ndr_print_NTTIME(ndr, "open_write_time", r->open_write_time);
	ndr_print_NTTIME(ndr, "changed_write_time", r->changed_write_time);
	ndr_print_string(ndr, "path", r->path);
	ndr_print_uint32(ndr, "num_entries", r->num_entries);
	ndr->print(ndr, "%s: ARRAY(%d)", "entries", (int)r->num_entries);
	ndr->depth++;
	for (cntr_entries_0 = 0; cntr_entries_0 < (r->num_entries); cntr_entries_0++) {
		ndr_print_opendb_entry(ndr, "entries", &r->entries[cntr_entries_0]);
	}
	ndr->depth--;
	ndr_print_uint32(ndr, "num_pending", r->num_pending);
	ndr->print(ndr, "%s: ARRAY(%d)", "pending", (int)r->num_pending);
	ndr->depth++;
	for (cntr_pending_0 = 0; cntr_pending_0 < (r->num_pending); cntr_pending_0++) {
		ndr_print_opendb_pending(ndr, "pending", &r->pending[cntr_pending_0]);
	}
	ndr->depth--;
	ndr->depth--;
}

