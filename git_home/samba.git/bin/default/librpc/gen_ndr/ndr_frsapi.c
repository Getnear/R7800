/* parser auto-generated by pidl */

#include "includes.h"
#include "bin/default/librpc/gen_ndr/ndr_frsapi.h"

#include "librpc/gen_ndr/ndr_misc.h"
static enum ndr_err_code ndr_push_frsapi_InfoEnum(struct ndr_push *ndr, int ndr_flags, enum frsapi_InfoEnum r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_InfoEnum(struct ndr_pull *ndr, int ndr_flags, enum frsapi_InfoEnum *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_InfoEnum(struct ndr_print *ndr, const char *name, enum frsapi_InfoEnum r)
{
	const char *val = NULL;

	switch (r) {
		case FRSAPI_INFO_VERSION: val = "FRSAPI_INFO_VERSION"; break;
		case FRSAPI_INFO_SETS: val = "FRSAPI_INFO_SETS"; break;
		case FRSAPI_INFO_DS: val = "FRSAPI_INFO_DS"; break;
		case FRSAPI_INFO_MEMORY: val = "FRSAPI_INFO_MEMORY"; break;
		case FRSAPI_INFO_IDTABLE: val = "FRSAPI_INFO_IDTABLE"; break;
		case FRSAPI_INFO_OUTLOG: val = "FRSAPI_INFO_OUTLOG"; break;
		case FRSAPI_INFO_INLOG: val = "FRSAPI_INFO_INLOG"; break;
		case FRSAPI_INFO_THREADS: val = "FRSAPI_INFO_THREADS"; break;
		case FRSAPI_INFO_STAGE: val = "FRSAPI_INFO_STAGE"; break;
		case FRSAPI_INFO_CONFIGTABLE: val = "FRSAPI_INFO_CONFIGTABLE"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_frsapi_Info(struct ndr_push *ndr, int ndr_flags, const struct frsapi_Info *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->length));
		NDR_CHECK(ndr_push_GUID(ndr, NDR_SCALARS, &r->guid));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->length2));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->unknown1));
		NDR_CHECK(ndr_push_frsapi_InfoEnum(ndr, NDR_SCALARS, r->level));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->query_counter));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->unknown2));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->offset));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->blob_len));
		{
			uint32_t _flags_save_DATA_BLOB = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_REMAINING);
			{
				struct ndr_push *_ndr_blob;
				NDR_CHECK(ndr_push_subcontext_start(ndr, &_ndr_blob, 0, r->length - r->offset));
				NDR_CHECK(ndr_push_DATA_BLOB(_ndr_blob, NDR_SCALARS, r->blob));
				NDR_CHECK(ndr_push_subcontext_end(ndr, _ndr_blob, 0, r->length - r->offset));
			}
			ndr->flags = _flags_save_DATA_BLOB;
		}
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_Info(struct ndr_pull *ndr, int ndr_flags, struct frsapi_Info *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->length));
		NDR_CHECK(ndr_pull_GUID(ndr, NDR_SCALARS, &r->guid));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->length2));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->unknown1));
		NDR_CHECK(ndr_pull_frsapi_InfoEnum(ndr, NDR_SCALARS, &r->level));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->query_counter));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->unknown2));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->offset));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->blob_len));
		{
			uint32_t _flags_save_DATA_BLOB = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_REMAINING);
			{
				struct ndr_pull *_ndr_blob;
				NDR_CHECK(ndr_pull_subcontext_start(ndr, &_ndr_blob, 0, r->length - r->offset));
				NDR_CHECK(ndr_pull_DATA_BLOB(_ndr_blob, NDR_SCALARS, &r->blob));
				NDR_CHECK(ndr_pull_subcontext_end(ndr, _ndr_blob, 0, r->length - r->offset));
			}
			ndr->flags = _flags_save_DATA_BLOB;
		}
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_Info(struct ndr_print *ndr, const char *name, const struct frsapi_Info *r)
{
	ndr_print_struct(ndr, name, "frsapi_Info");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_uint32(ndr, "length", r->length);
	ndr_print_GUID(ndr, "guid", &r->guid);
	ndr_print_uint32(ndr, "length2", r->length2);
	ndr_print_uint32(ndr, "unknown1", r->unknown1);
	ndr_print_frsapi_InfoEnum(ndr, "level", r->level);
	ndr_print_uint32(ndr, "query_counter", r->query_counter);
	ndr_print_uint32(ndr, "unknown2", r->unknown2);
	ndr_print_uint32(ndr, "offset", r->offset);
	ndr_print_uint32(ndr, "blob_len", r->blob_len);
	ndr_print_DATA_BLOB(ndr, "blob", r->blob);
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_ReplicaSetType(struct ndr_push *ndr, int ndr_flags, enum frsapi_ReplicaSetType r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_ReplicaSetType(struct ndr_pull *ndr, int ndr_flags, enum frsapi_ReplicaSetType *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_ReplicaSetType(struct ndr_print *ndr, const char *name, enum frsapi_ReplicaSetType r)
{
	const char *val = NULL;

	switch (r) {
		case FRSAPI_REPLICA_SET_TYPE_0: val = "FRSAPI_REPLICA_SET_TYPE_0"; break;
		case FRSAPI_REPLICA_SET_TYPE_DOMAIN: val = "FRSAPI_REPLICA_SET_TYPE_DOMAIN"; break;
		case FRSAPI_REPLICA_SET_TYPE_DFS: val = "FRSAPI_REPLICA_SET_TYPE_DFS"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_frsapi_WriterCommandsValues(struct ndr_push *ndr, int ndr_flags, enum frsapi_WriterCommandsValues r)
{
	NDR_CHECK(ndr_push_enum_uint32(ndr, NDR_SCALARS, r));
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_WriterCommandsValues(struct ndr_pull *ndr, int ndr_flags, enum frsapi_WriterCommandsValues *r)
{
	uint32_t v;
	NDR_CHECK(ndr_pull_enum_uint32(ndr, NDR_SCALARS, &v));
	*r = v;
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_WriterCommandsValues(struct ndr_print *ndr, const char *name, enum frsapi_WriterCommandsValues r)
{
	const char *val = NULL;

	switch (r) {
		case FRSAPI_WRITER_COMMAND_FREEZE: val = "FRSAPI_WRITER_COMMAND_FREEZE"; break;
		case FRSAPI_WRITER_COMMAND_THAW: val = "FRSAPI_WRITER_COMMAND_THAW"; break;
	}
	ndr_print_enum(ndr, name, "ENUM", val, r);
}

static enum ndr_err_code ndr_push_FRSAPI_VERIFY_PROMOTION(struct ndr_push *ndr, int flags, const struct FRSAPI_VERIFY_PROMOTION *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_FRSAPI_VERIFY_PROMOTION(struct ndr_pull *ndr, int flags, struct FRSAPI_VERIFY_PROMOTION *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_FRSAPI_VERIFY_PROMOTION(struct ndr_print *ndr, const char *name, int flags, const struct FRSAPI_VERIFY_PROMOTION *r)
{
	ndr_print_struct(ndr, name, "FRSAPI_VERIFY_PROMOTION");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "FRSAPI_VERIFY_PROMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "FRSAPI_VERIFY_PROMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_FRSAPI_PROMOTION_STATUS(struct ndr_push *ndr, int flags, const struct FRSAPI_PROMOTION_STATUS *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_FRSAPI_PROMOTION_STATUS(struct ndr_pull *ndr, int flags, struct FRSAPI_PROMOTION_STATUS *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_FRSAPI_PROMOTION_STATUS(struct ndr_print *ndr, const char *name, int flags, const struct FRSAPI_PROMOTION_STATUS *r)
{
	ndr_print_struct(ndr, name, "FRSAPI_PROMOTION_STATUS");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "FRSAPI_PROMOTION_STATUS");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "FRSAPI_PROMOTION_STATUS");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_FRSAPI_START_DEMOTION(struct ndr_push *ndr, int flags, const struct FRSAPI_START_DEMOTION *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_FRSAPI_START_DEMOTION(struct ndr_pull *ndr, int flags, struct FRSAPI_START_DEMOTION *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_FRSAPI_START_DEMOTION(struct ndr_print *ndr, const char *name, int flags, const struct FRSAPI_START_DEMOTION *r)
{
	ndr_print_struct(ndr, name, "FRSAPI_START_DEMOTION");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "FRSAPI_START_DEMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "FRSAPI_START_DEMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_FRSAPI_COMMIT_DEMOTION(struct ndr_push *ndr, int flags, const struct FRSAPI_COMMIT_DEMOTION *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_FRSAPI_COMMIT_DEMOTION(struct ndr_pull *ndr, int flags, struct FRSAPI_COMMIT_DEMOTION *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_FRSAPI_COMMIT_DEMOTION(struct ndr_print *ndr, const char *name, int flags, const struct FRSAPI_COMMIT_DEMOTION *r)
{
	ndr_print_struct(ndr, name, "FRSAPI_COMMIT_DEMOTION");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "FRSAPI_COMMIT_DEMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "FRSAPI_COMMIT_DEMOTION");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_SetDsPollingIntervalW(struct ndr_push *ndr, int flags, const struct frsapi_SetDsPollingIntervalW *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.CurrentInterval));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.DsPollingLongInterval));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.DsPollingShortInterval));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_SetDsPollingIntervalW(struct ndr_pull *ndr, int flags, struct frsapi_SetDsPollingIntervalW *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.CurrentInterval));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.DsPollingLongInterval));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.DsPollingShortInterval));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_SetDsPollingIntervalW(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_SetDsPollingIntervalW *r)
{
	ndr_print_struct(ndr, name, "frsapi_SetDsPollingIntervalW");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_SetDsPollingIntervalW");
		ndr->depth++;
		ndr_print_uint32(ndr, "CurrentInterval", r->in.CurrentInterval);
		ndr_print_uint32(ndr, "DsPollingLongInterval", r->in.DsPollingLongInterval);
		ndr_print_uint32(ndr, "DsPollingShortInterval", r->in.DsPollingShortInterval);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_SetDsPollingIntervalW");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_GetDsPollingIntervalW(struct ndr_push *ndr, int flags, const struct frsapi_GetDsPollingIntervalW *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
		if (r->out.CurrentInterval == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		if (r->out.DsPollingLongInterval == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		if (r->out.DsPollingShortInterval == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.CurrentInterval));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.DsPollingLongInterval));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.DsPollingShortInterval));
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_GetDsPollingIntervalW(struct ndr_pull *ndr, int flags, struct frsapi_GetDsPollingIntervalW *r)
{
	TALLOC_CTX *_mem_save_CurrentInterval_0 = NULL;
	TALLOC_CTX *_mem_save_DsPollingLongInterval_0 = NULL;
	TALLOC_CTX *_mem_save_DsPollingShortInterval_0 = NULL;
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		ZERO_STRUCT(r->out);

		NDR_PULL_ALLOC(ndr, r->out.CurrentInterval);
		ZERO_STRUCTP(r->out.CurrentInterval);
		NDR_PULL_ALLOC(ndr, r->out.DsPollingLongInterval);
		ZERO_STRUCTP(r->out.DsPollingLongInterval);
		NDR_PULL_ALLOC(ndr, r->out.DsPollingShortInterval);
		ZERO_STRUCTP(r->out.DsPollingShortInterval);
	}
	if (flags & NDR_OUT) {
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.CurrentInterval);
		}
		_mem_save_CurrentInterval_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.CurrentInterval, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.CurrentInterval));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_CurrentInterval_0, LIBNDR_FLAG_REF_ALLOC);
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.DsPollingLongInterval);
		}
		_mem_save_DsPollingLongInterval_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.DsPollingLongInterval, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.DsPollingLongInterval));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_DsPollingLongInterval_0, LIBNDR_FLAG_REF_ALLOC);
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.DsPollingShortInterval);
		}
		_mem_save_DsPollingShortInterval_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.DsPollingShortInterval, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.DsPollingShortInterval));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_DsPollingShortInterval_0, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_GetDsPollingIntervalW(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_GetDsPollingIntervalW *r)
{
	ndr_print_struct(ndr, name, "frsapi_GetDsPollingIntervalW");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_GetDsPollingIntervalW");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_GetDsPollingIntervalW");
		ndr->depth++;
		ndr_print_ptr(ndr, "CurrentInterval", r->out.CurrentInterval);
		ndr->depth++;
		ndr_print_uint32(ndr, "CurrentInterval", *r->out.CurrentInterval);
		ndr->depth--;
		ndr_print_ptr(ndr, "DsPollingLongInterval", r->out.DsPollingLongInterval);
		ndr->depth++;
		ndr_print_uint32(ndr, "DsPollingLongInterval", *r->out.DsPollingLongInterval);
		ndr->depth--;
		ndr_print_ptr(ndr, "DsPollingShortInterval", r->out.DsPollingShortInterval);
		ndr->depth++;
		ndr_print_uint32(ndr, "DsPollingShortInterval", *r->out.DsPollingShortInterval);
		ndr->depth--;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_FRSAPI_VERIFY_PROMOTION_W(struct ndr_push *ndr, int flags, const struct FRSAPI_VERIFY_PROMOTION_W *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_FRSAPI_VERIFY_PROMOTION_W(struct ndr_pull *ndr, int flags, struct FRSAPI_VERIFY_PROMOTION_W *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
	}
	if (flags & NDR_OUT) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_FRSAPI_VERIFY_PROMOTION_W(struct ndr_print *ndr, const char *name, int flags, const struct FRSAPI_VERIFY_PROMOTION_W *r)
{
	ndr_print_struct(ndr, name, "FRSAPI_VERIFY_PROMOTION_W");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "FRSAPI_VERIFY_PROMOTION_W");
		ndr->depth++;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "FRSAPI_VERIFY_PROMOTION_W");
		ndr->depth++;
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_InfoW(struct ndr_push *ndr, int flags, const struct frsapi_InfoW *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.length));
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.info));
		if (r->in.info) {
			NDR_CHECK(ndr_push_frsapi_Info(ndr, NDR_SCALARS, r->in.info));
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->out.info));
		if (r->out.info) {
			NDR_CHECK(ndr_push_frsapi_Info(ndr, NDR_SCALARS, r->out.info));
		}
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_InfoW(struct ndr_pull *ndr, int flags, struct frsapi_InfoW *r)
{
	uint32_t _ptr_info;
	TALLOC_CTX *_mem_save_info_0 = NULL;
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		ZERO_STRUCT(r->out);

		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.length));
		if (r->in.length > 0x10000) {
			return ndr_pull_error(ndr, NDR_ERR_RANGE, "value out of range");
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_info));
		if (_ptr_info) {
			NDR_PULL_ALLOC(ndr, r->in.info);
		} else {
			r->in.info = NULL;
		}
		if (r->in.info) {
			_mem_save_info_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.info, 0);
			NDR_CHECK(ndr_pull_frsapi_Info(ndr, NDR_SCALARS, r->in.info));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_info_0, 0);
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_info));
		if (_ptr_info) {
			NDR_PULL_ALLOC(ndr, r->out.info);
		} else {
			r->out.info = NULL;
		}
		if (r->out.info) {
			_mem_save_info_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->out.info, 0);
			NDR_CHECK(ndr_pull_frsapi_Info(ndr, NDR_SCALARS, r->out.info));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_info_0, 0);
		}
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_InfoW(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_InfoW *r)
{
	ndr_print_struct(ndr, name, "frsapi_InfoW");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_InfoW");
		ndr->depth++;
		ndr_print_uint32(ndr, "length", r->in.length);
		ndr_print_ptr(ndr, "info", r->in.info);
		ndr->depth++;
		if (r->in.info) {
			ndr_print_frsapi_Info(ndr, "info", r->in.info);
		}
		ndr->depth--;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_InfoW");
		ndr->depth++;
		ndr_print_ptr(ndr, "info", r->out.info);
		ndr->depth++;
		if (r->out.info) {
			ndr_print_frsapi_Info(ndr, "info", r->out.info);
		}
		ndr->depth--;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_IsPathReplicated(struct ndr_push *ndr, int flags, const struct frsapi_IsPathReplicated *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.path));
		if (r->in.path) {
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.path, CH_UTF16)));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, 0));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.path, CH_UTF16)));
			NDR_CHECK(ndr_push_charset(ndr, NDR_SCALARS, r->in.path, ndr_charset_length(r->in.path, CH_UTF16), sizeof(uint16_t), CH_UTF16));
		}
		NDR_CHECK(ndr_push_frsapi_ReplicaSetType(ndr, NDR_SCALARS, r->in.replica_set_type));
	}
	if (flags & NDR_OUT) {
		if (r->out.replicated == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		if (r->out.primary == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		if (r->out.root == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		if (r->out.replica_set_guid == NULL) {
			return ndr_push_error(ndr, NDR_ERR_INVALID_POINTER, "NULL [ref] pointer");
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.replicated));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.primary));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, *r->out.root));
		NDR_CHECK(ndr_push_GUID(ndr, NDR_SCALARS, r->out.replica_set_guid));
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_IsPathReplicated(struct ndr_pull *ndr, int flags, struct frsapi_IsPathReplicated *r)
{
	uint32_t _ptr_path;
	uint32_t size_path_1 = 0;
	uint32_t length_path_1 = 0;
	TALLOC_CTX *_mem_save_path_0 = NULL;
	TALLOC_CTX *_mem_save_replicated_0 = NULL;
	TALLOC_CTX *_mem_save_primary_0 = NULL;
	TALLOC_CTX *_mem_save_root_0 = NULL;
	TALLOC_CTX *_mem_save_replica_set_guid_0 = NULL;
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		ZERO_STRUCT(r->out);

		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_path));
		if (_ptr_path) {
			NDR_PULL_ALLOC(ndr, r->in.path);
		} else {
			r->in.path = NULL;
		}
		if (r->in.path) {
			_mem_save_path_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.path, 0);
			NDR_CHECK(ndr_pull_array_size(ndr, &r->in.path));
			NDR_CHECK(ndr_pull_array_length(ndr, &r->in.path));
			size_path_1 = ndr_get_array_size(ndr, &r->in.path);
			length_path_1 = ndr_get_array_length(ndr, &r->in.path);
			if (length_path_1 > size_path_1) {
				return ndr_pull_error(ndr, NDR_ERR_ARRAY_SIZE, "Bad array size %u should exceed array length %u", size_path_1, length_path_1);
			}
			NDR_CHECK(ndr_check_string_terminator(ndr, length_path_1, sizeof(uint16_t)));
			NDR_CHECK(ndr_pull_charset(ndr, NDR_SCALARS, &r->in.path, length_path_1, sizeof(uint16_t), CH_UTF16));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_path_0, 0);
		}
		NDR_CHECK(ndr_pull_frsapi_ReplicaSetType(ndr, NDR_SCALARS, &r->in.replica_set_type));
		NDR_PULL_ALLOC(ndr, r->out.replicated);
		ZERO_STRUCTP(r->out.replicated);
		NDR_PULL_ALLOC(ndr, r->out.primary);
		ZERO_STRUCTP(r->out.primary);
		NDR_PULL_ALLOC(ndr, r->out.root);
		ZERO_STRUCTP(r->out.root);
		NDR_PULL_ALLOC(ndr, r->out.replica_set_guid);
		ZERO_STRUCTP(r->out.replica_set_guid);
	}
	if (flags & NDR_OUT) {
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.replicated);
		}
		_mem_save_replicated_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.replicated, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.replicated));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_replicated_0, LIBNDR_FLAG_REF_ALLOC);
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.primary);
		}
		_mem_save_primary_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.primary, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.primary));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_primary_0, LIBNDR_FLAG_REF_ALLOC);
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.root);
		}
		_mem_save_root_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.root, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, r->out.root));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_root_0, LIBNDR_FLAG_REF_ALLOC);
		if (ndr->flags & LIBNDR_FLAG_REF_ALLOC) {
			NDR_PULL_ALLOC(ndr, r->out.replica_set_guid);
		}
		_mem_save_replica_set_guid_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->out.replica_set_guid, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_GUID(ndr, NDR_SCALARS, r->out.replica_set_guid));
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_replica_set_guid_0, LIBNDR_FLAG_REF_ALLOC);
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_IsPathReplicated(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_IsPathReplicated *r)
{
	ndr_print_struct(ndr, name, "frsapi_IsPathReplicated");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_IsPathReplicated");
		ndr->depth++;
		ndr_print_ptr(ndr, "path", r->in.path);
		ndr->depth++;
		if (r->in.path) {
			ndr_print_string(ndr, "path", r->in.path);
		}
		ndr->depth--;
		ndr_print_frsapi_ReplicaSetType(ndr, "replica_set_type", r->in.replica_set_type);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_IsPathReplicated");
		ndr->depth++;
		ndr_print_ptr(ndr, "replicated", r->out.replicated);
		ndr->depth++;
		ndr_print_uint32(ndr, "replicated", *r->out.replicated);
		ndr->depth--;
		ndr_print_ptr(ndr, "primary", r->out.primary);
		ndr->depth++;
		ndr_print_uint32(ndr, "primary", *r->out.primary);
		ndr->depth--;
		ndr_print_ptr(ndr, "root", r->out.root);
		ndr->depth++;
		ndr_print_uint32(ndr, "root", *r->out.root);
		ndr->depth--;
		ndr_print_ptr(ndr, "replica_set_guid", r->out.replica_set_guid);
		ndr->depth++;
		ndr_print_GUID(ndr, "replica_set_guid", r->out.replica_set_guid);
		ndr->depth--;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_WriterCommand(struct ndr_push *ndr, int flags, const struct frsapi_WriterCommand *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_frsapi_WriterCommandsValues(ndr, NDR_SCALARS, r->in.command));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_WriterCommand(struct ndr_pull *ndr, int flags, struct frsapi_WriterCommand *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_frsapi_WriterCommandsValues(ndr, NDR_SCALARS, &r->in.command));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_WriterCommand(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_WriterCommand *r)
{
	ndr_print_struct(ndr, name, "frsapi_WriterCommand");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_WriterCommand");
		ndr->depth++;
		ndr_print_frsapi_WriterCommandsValues(ndr, "command", r->in.command);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_WriterCommand");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_frsapi_ForceReplication(struct ndr_push *ndr, int flags, const struct frsapi_ForceReplication *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.replica_set_guid));
		if (r->in.replica_set_guid) {
			NDR_CHECK(ndr_push_GUID(ndr, NDR_SCALARS, r->in.replica_set_guid));
		}
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.connection_guid));
		if (r->in.connection_guid) {
			NDR_CHECK(ndr_push_GUID(ndr, NDR_SCALARS, r->in.connection_guid));
		}
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.replica_set_name));
		if (r->in.replica_set_name) {
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.replica_set_name, CH_UTF16)));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, 0));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.replica_set_name, CH_UTF16)));
			NDR_CHECK(ndr_push_charset(ndr, NDR_SCALARS, r->in.replica_set_name, ndr_charset_length(r->in.replica_set_name, CH_UTF16), sizeof(uint16_t), CH_UTF16));
		}
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.partner_dns_name));
		if (r->in.partner_dns_name) {
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.partner_dns_name, CH_UTF16)));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, 0));
			NDR_CHECK(ndr_push_uint3264(ndr, NDR_SCALARS, ndr_charset_length(r->in.partner_dns_name, CH_UTF16)));
			NDR_CHECK(ndr_push_charset(ndr, NDR_SCALARS, r->in.partner_dns_name, ndr_charset_length(r->in.partner_dns_name, CH_UTF16), sizeof(uint16_t), CH_UTF16));
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_frsapi_ForceReplication(struct ndr_pull *ndr, int flags, struct frsapi_ForceReplication *r)
{
	uint32_t _ptr_replica_set_guid;
	uint32_t _ptr_connection_guid;
	uint32_t _ptr_replica_set_name;
	uint32_t size_replica_set_name_1 = 0;
	uint32_t length_replica_set_name_1 = 0;
	uint32_t _ptr_partner_dns_name;
	uint32_t size_partner_dns_name_1 = 0;
	uint32_t length_partner_dns_name_1 = 0;
	TALLOC_CTX *_mem_save_replica_set_guid_0 = NULL;
	TALLOC_CTX *_mem_save_connection_guid_0 = NULL;
	TALLOC_CTX *_mem_save_replica_set_name_0 = NULL;
	TALLOC_CTX *_mem_save_partner_dns_name_0 = NULL;
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_replica_set_guid));
		if (_ptr_replica_set_guid) {
			NDR_PULL_ALLOC(ndr, r->in.replica_set_guid);
		} else {
			r->in.replica_set_guid = NULL;
		}
		if (r->in.replica_set_guid) {
			_mem_save_replica_set_guid_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.replica_set_guid, 0);
			NDR_CHECK(ndr_pull_GUID(ndr, NDR_SCALARS, r->in.replica_set_guid));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_replica_set_guid_0, 0);
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_connection_guid));
		if (_ptr_connection_guid) {
			NDR_PULL_ALLOC(ndr, r->in.connection_guid);
		} else {
			r->in.connection_guid = NULL;
		}
		if (r->in.connection_guid) {
			_mem_save_connection_guid_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.connection_guid, 0);
			NDR_CHECK(ndr_pull_GUID(ndr, NDR_SCALARS, r->in.connection_guid));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_connection_guid_0, 0);
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_replica_set_name));
		if (_ptr_replica_set_name) {
			NDR_PULL_ALLOC(ndr, r->in.replica_set_name);
		} else {
			r->in.replica_set_name = NULL;
		}
		if (r->in.replica_set_name) {
			_mem_save_replica_set_name_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.replica_set_name, 0);
			NDR_CHECK(ndr_pull_array_size(ndr, &r->in.replica_set_name));
			NDR_CHECK(ndr_pull_array_length(ndr, &r->in.replica_set_name));
			size_replica_set_name_1 = ndr_get_array_size(ndr, &r->in.replica_set_name);
			length_replica_set_name_1 = ndr_get_array_length(ndr, &r->in.replica_set_name);
			if (length_replica_set_name_1 > size_replica_set_name_1) {
				return ndr_pull_error(ndr, NDR_ERR_ARRAY_SIZE, "Bad array size %u should exceed array length %u", size_replica_set_name_1, length_replica_set_name_1);
			}
			NDR_CHECK(ndr_check_string_terminator(ndr, length_replica_set_name_1, sizeof(uint16_t)));
			NDR_CHECK(ndr_pull_charset(ndr, NDR_SCALARS, &r->in.replica_set_name, length_replica_set_name_1, sizeof(uint16_t), CH_UTF16));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_replica_set_name_0, 0);
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_partner_dns_name));
		if (_ptr_partner_dns_name) {
			NDR_PULL_ALLOC(ndr, r->in.partner_dns_name);
		} else {
			r->in.partner_dns_name = NULL;
		}
		if (r->in.partner_dns_name) {
			_mem_save_partner_dns_name_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.partner_dns_name, 0);
			NDR_CHECK(ndr_pull_array_size(ndr, &r->in.partner_dns_name));
			NDR_CHECK(ndr_pull_array_length(ndr, &r->in.partner_dns_name));
			size_partner_dns_name_1 = ndr_get_array_size(ndr, &r->in.partner_dns_name);
			length_partner_dns_name_1 = ndr_get_array_length(ndr, &r->in.partner_dns_name);
			if (length_partner_dns_name_1 > size_partner_dns_name_1) {
				return ndr_pull_error(ndr, NDR_ERR_ARRAY_SIZE, "Bad array size %u should exceed array length %u", size_partner_dns_name_1, length_partner_dns_name_1);
			}
			NDR_CHECK(ndr_check_string_terminator(ndr, length_partner_dns_name_1, sizeof(uint16_t)));
			NDR_CHECK(ndr_pull_charset(ndr, NDR_SCALARS, &r->in.partner_dns_name, length_partner_dns_name_1, sizeof(uint16_t), CH_UTF16));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_partner_dns_name_0, 0);
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_frsapi_ForceReplication(struct ndr_print *ndr, const char *name, int flags, const struct frsapi_ForceReplication *r)
{
	ndr_print_struct(ndr, name, "frsapi_ForceReplication");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "frsapi_ForceReplication");
		ndr->depth++;
		ndr_print_ptr(ndr, "replica_set_guid", r->in.replica_set_guid);
		ndr->depth++;
		if (r->in.replica_set_guid) {
			ndr_print_GUID(ndr, "replica_set_guid", r->in.replica_set_guid);
		}
		ndr->depth--;
		ndr_print_ptr(ndr, "connection_guid", r->in.connection_guid);
		ndr->depth++;
		if (r->in.connection_guid) {
			ndr_print_GUID(ndr, "connection_guid", r->in.connection_guid);
		}
		ndr->depth--;
		ndr_print_ptr(ndr, "replica_set_name", r->in.replica_set_name);
		ndr->depth++;
		if (r->in.replica_set_name) {
			ndr_print_string(ndr, "replica_set_name", r->in.replica_set_name);
		}
		ndr->depth--;
		ndr_print_ptr(ndr, "partner_dns_name", r->in.partner_dns_name);
		ndr->depth++;
		if (r->in.partner_dns_name) {
			ndr_print_string(ndr, "partner_dns_name", r->in.partner_dns_name);
		}
		ndr->depth--;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "frsapi_ForceReplication");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static const struct ndr_interface_call frsapi_calls[] = {
	{
		"FRSAPI_VERIFY_PROMOTION",
		sizeof(struct FRSAPI_VERIFY_PROMOTION),
		(ndr_push_flags_fn_t) ndr_push_FRSAPI_VERIFY_PROMOTION,
		(ndr_pull_flags_fn_t) ndr_pull_FRSAPI_VERIFY_PROMOTION,
		(ndr_print_function_t) ndr_print_FRSAPI_VERIFY_PROMOTION,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"FRSAPI_PROMOTION_STATUS",
		sizeof(struct FRSAPI_PROMOTION_STATUS),
		(ndr_push_flags_fn_t) ndr_push_FRSAPI_PROMOTION_STATUS,
		(ndr_pull_flags_fn_t) ndr_pull_FRSAPI_PROMOTION_STATUS,
		(ndr_print_function_t) ndr_print_FRSAPI_PROMOTION_STATUS,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"FRSAPI_START_DEMOTION",
		sizeof(struct FRSAPI_START_DEMOTION),
		(ndr_push_flags_fn_t) ndr_push_FRSAPI_START_DEMOTION,
		(ndr_pull_flags_fn_t) ndr_pull_FRSAPI_START_DEMOTION,
		(ndr_print_function_t) ndr_print_FRSAPI_START_DEMOTION,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"FRSAPI_COMMIT_DEMOTION",
		sizeof(struct FRSAPI_COMMIT_DEMOTION),
		(ndr_push_flags_fn_t) ndr_push_FRSAPI_COMMIT_DEMOTION,
		(ndr_pull_flags_fn_t) ndr_pull_FRSAPI_COMMIT_DEMOTION,
		(ndr_print_function_t) ndr_print_FRSAPI_COMMIT_DEMOTION,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_SetDsPollingIntervalW",
		sizeof(struct frsapi_SetDsPollingIntervalW),
		(ndr_push_flags_fn_t) ndr_push_frsapi_SetDsPollingIntervalW,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_SetDsPollingIntervalW,
		(ndr_print_function_t) ndr_print_frsapi_SetDsPollingIntervalW,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_GetDsPollingIntervalW",
		sizeof(struct frsapi_GetDsPollingIntervalW),
		(ndr_push_flags_fn_t) ndr_push_frsapi_GetDsPollingIntervalW,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_GetDsPollingIntervalW,
		(ndr_print_function_t) ndr_print_frsapi_GetDsPollingIntervalW,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"FRSAPI_VERIFY_PROMOTION_W",
		sizeof(struct FRSAPI_VERIFY_PROMOTION_W),
		(ndr_push_flags_fn_t) ndr_push_FRSAPI_VERIFY_PROMOTION_W,
		(ndr_pull_flags_fn_t) ndr_pull_FRSAPI_VERIFY_PROMOTION_W,
		(ndr_print_function_t) ndr_print_FRSAPI_VERIFY_PROMOTION_W,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_InfoW",
		sizeof(struct frsapi_InfoW),
		(ndr_push_flags_fn_t) ndr_push_frsapi_InfoW,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_InfoW,
		(ndr_print_function_t) ndr_print_frsapi_InfoW,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_IsPathReplicated",
		sizeof(struct frsapi_IsPathReplicated),
		(ndr_push_flags_fn_t) ndr_push_frsapi_IsPathReplicated,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_IsPathReplicated,
		(ndr_print_function_t) ndr_print_frsapi_IsPathReplicated,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_WriterCommand",
		sizeof(struct frsapi_WriterCommand),
		(ndr_push_flags_fn_t) ndr_push_frsapi_WriterCommand,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_WriterCommand,
		(ndr_print_function_t) ndr_print_frsapi_WriterCommand,
		{ 0, NULL },
		{ 0, NULL },
	},
	{
		"frsapi_ForceReplication",
		sizeof(struct frsapi_ForceReplication),
		(ndr_push_flags_fn_t) ndr_push_frsapi_ForceReplication,
		(ndr_pull_flags_fn_t) ndr_pull_frsapi_ForceReplication,
		(ndr_print_function_t) ndr_print_frsapi_ForceReplication,
		{ 0, NULL },
		{ 0, NULL },
	},
	{ NULL, 0, NULL, NULL, NULL }
};

static const char * const frsapi_endpoint_strings[] = {
	"ncacn_ip_tcp:", 
	"ncalrpc:", 
};

static const struct ndr_interface_string_array frsapi_endpoints = {
	.count	= 2,
	.names	= frsapi_endpoint_strings
};

static const char * const frsapi_authservice_strings[] = {
	"host", 
};

static const struct ndr_interface_string_array frsapi_authservices = {
	.count	= 1,
	.names	= frsapi_authservice_strings
};


const struct ndr_interface_table ndr_table_frsapi = {
	.name		= "frsapi",
	.syntax_id	= {
		{0xd049b186,0x814f,0x11d1,{0x9a,0x3c},{0x00,0xc0,0x4f,0xc9,0xb2,0x32}},
		NDR_FRSAPI_VERSION
	},
	.helpstring	= NDR_FRSAPI_HELPSTRING,
	.num_calls	= 11,
	.calls		= frsapi_calls,
	.endpoints	= &frsapi_endpoints,
	.authservices	= &frsapi_authservices
};

