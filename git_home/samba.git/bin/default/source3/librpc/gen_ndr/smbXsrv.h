/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_smbXsrv
#define _PIDL_HEADER_smbXsrv

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#include "librpc/gen_ndr/server_id.h"
#include "librpc/gen_ndr/security.h"
#include "librpc/gen_ndr/auth.h"
#ifndef _HEADER_smbXsrv
#define _HEADER_smbXsrv

#define SMBXSRV_VERSION_CURRENT	( SMBXSRV_VERSION_0 )
enum smbXsrv_version_values
#ifndef USE_UINT_ENUMS
 {
	SMBXSRV_VERSION_0=(int)(0x00000000)
}
#else
 { __do_not_use_enum_smbXsrv_version_values=0x7FFFFFFF}
#define SMBXSRV_VERSION_0 ( 0x00000000 )
#endif
;

struct smbXsrv_version_node0 {
	struct server_id server_id;
	enum smbXsrv_version_values min_version;
	enum smbXsrv_version_values max_version;
	enum smbXsrv_version_values current_version;
};

struct smbXsrv_version_global0 {
	struct db_record *db_rec;/* [ignore] */
	uint32_t num_nodes;/* [range(1,1024)] */
	struct smbXsrv_version_node0 *nodes;
};

union smbXsrv_version_globalU {
	struct smbXsrv_version_global0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_version_globalB {
	enum smbXsrv_version_values version;
	uint32_t seqnum;
	union smbXsrv_version_globalU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_client_global0 {
	struct db_record *db_rec;/* [ignore] */
	struct server_id server_id;
	const char *local_address;/* [charset(UTF8)] */
	const char *remote_address;/* [charset(UTF8)] */
	const char *remote_name;/* [charset(UTF8)] */
	NTTIME initial_connect_time;
	struct GUID client_guid;
	uint8_t stored;
};

union smbXsrv_client_globalU {
	struct smbXsrv_client_global0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_client_globalB {
	enum smbXsrv_version_values version;
	uint32_t seqnum;
	union smbXsrv_client_globalU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_client {
	struct smbXsrv_client_table *table;/* [ignore] */
	struct tevent_context *ev_ctx;/* [ignore] */
	struct messaging_context *msg_ctx;/* [ignore] */
	struct smbXsrv_client_global0 *global;/* [ref] */
	struct smbd_server_connection *sconn;/* [ignore] */
	struct smbXsrv_session_table *session_table;/* [ignore] */
	uint64_t last_session_id;/* [ignore] */
	struct smbXsrv_tcon_table *tcon_table;/* [ignore] */
	struct smbXsrv_open_table *open_table;/* [ignore] */
	struct smbXsrv_connection *connections;/* [ignore] */
	uint8_t server_multi_channel_enabled;
}/* [public] */;

union smbXsrv_clientU {
	struct smbXsrv_client *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_clientB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_clientU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_connection_pass0 {
	NTTIME initial_connect_time;
	struct GUID client_guid;
	DATA_BLOB negotiate_request;
};

union smbXsrv_connection_passU {
	struct smbXsrv_connection_pass0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_connection_passB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_connection_passU info;/* [switch_is(version)] */
}/* [public] */;

/* bitmap smbXsrv_encrpytion_flags */
#define SMBXSRV_ENCRYPTION_REQUIRED ( 0x01 )
#define SMBXSRV_ENCRYPTION_DESIRED ( 0x02 )
#define SMBXSRV_PROCESSED_ENCRYPTED_PACKET ( 0x04 )
#define SMBXSRV_PROCESSED_UNENCRYPTED_PACKET ( 0x08 )

/* bitmap smbXsrv_signing_flags */
#define SMBXSRV_SIGNING_REQUIRED ( 0x01 )
#define SMBXSRV_PROCESSED_SIGNED_PACKET ( 0x02 )
#define SMBXSRV_PROCESSED_UNSIGNED_PACKET ( 0x04 )

struct smbXsrv_channel_global0 {
	struct server_id server_id;
	const char *local_address;/* [charset(UTF8)] */
	const char *remote_address;/* [charset(UTF8)] */
	const char *remote_name;/* [charset(UTF8)] */
	DATA_BLOB signing_key;/* [noprint] */
	uint32_t auth_session_info_seqnum;
	struct smbXsrv_connection *connection;/* [ignore] */
	uint16_t encryption_cipher;
};

struct smbXsrv_session_global0 {
	struct db_record *db_rec;/* [ignore] */
	uint32_t session_global_id;
	uint64_t session_wire_id;
	NTTIME creation_time;
	NTTIME expiration_time;
	NTTIME auth_time;
	uint32_t auth_session_info_seqnum;
	struct auth_session_info *auth_session_info;/* [unique] */
	uint16_t connection_dialect;
	uint8_t signing_flags;
	uint8_t encryption_flags;
	DATA_BLOB signing_key;/* [noprint] */
	DATA_BLOB encryption_key;/* [noprint] */
	DATA_BLOB decryption_key;/* [noprint] */
	DATA_BLOB application_key;/* [noprint] */
	uint32_t num_channels;/* [range(1,1024)] */
	struct smbXsrv_channel_global0 *channels;
};

union smbXsrv_session_globalU {
	struct smbXsrv_session_global0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_session_globalB {
	enum smbXsrv_version_values version;
	uint32_t seqnum;
	union smbXsrv_session_globalU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_session_auth0 {
	struct smbXsrv_session_auth0 *prev;/* [ignore] */
	struct smbXsrv_session_auth0 *next;/* [unique] */
	struct smbXsrv_session *session;/* [ignore] */
	struct smbXsrv_connection *connection;/* [ignore] */
	struct gensec_security *gensec;/* [ignore] */
	struct smbXsrv_preauth *preauth;/* [ignore] */
	uint8_t in_flags;
	uint8_t in_security_mode;
	NTTIME creation_time;
	NTTIME idle_time;
};

struct smbXsrv_session {
	struct smbXsrv_session_table *table;/* [ignore] */
	struct db_record *db_rec;/* [ignore] */
	struct smbXsrv_client *client;/* [ignore] */
	uint32_t local_id;
	struct smbXsrv_session_global0 *global;/* [ref] */
	NTSTATUS status;
	NTTIME idle_time;
	uint64_t nonce_high_random;
	uint64_t nonce_high_max;
	uint64_t nonce_high;
	uint64_t nonce_low;
	struct user_struct *compat;/* [ignore] */
	struct smbXsrv_tcon_table *tcon_table;/* [ignore] */
	struct smbXsrv_session_auth0 *pending_auth;/* [unique] */
};

union smbXsrv_sessionU {
	struct smbXsrv_session *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_sessionB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_sessionU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_session_close0 {
	uint32_t old_session_global_id;
	uint64_t old_session_wire_id;
	NTTIME old_creation_time;
	uint64_t new_session_wire_id;
};

union smbXsrv_session_closeU {
	struct smbXsrv_session_close0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_session_closeB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_session_closeU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_tcon_global0 {
	struct db_record *db_rec;/* [ignore] */
	uint32_t tcon_global_id;
	uint32_t tcon_wire_id;
	struct server_id server_id;
	NTTIME creation_time;
	const char *share_name;/* [charset(UTF8)] */
	uint8_t encryption_flags;
	uint32_t session_global_id;
	uint8_t signing_flags;
};

union smbXsrv_tcon_globalU {
	struct smbXsrv_tcon_global0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_tcon_globalB {
	enum smbXsrv_version_values version;
	uint32_t seqnum;
	union smbXsrv_tcon_globalU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_tcon {
	struct smbXsrv_tcon_table *table;/* [ignore] */
	struct db_record *db_rec;/* [ignore] */
	uint32_t local_id;
	struct smbXsrv_tcon_global0 *global;/* [ref] */
	NTSTATUS status;
	NTTIME idle_time;
	struct connection_struct *compat;/* [ignore] */
};

union smbXsrv_tconU {
	struct smbXsrv_tcon *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_tconB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_tconU info;/* [switch_is(version)] */
}/* [public] */;

/* bitmap smbXsrv_open_flags */
#define SMBXSRV_OPEN_NEED_REPLAY_CACHE ( 0x01 )
#define SMBXSRV_OPEN_HAVE_REPLAY_CACHE ( 0x02 )

struct smbXsrv_open_global0 {
	struct db_record *db_rec;/* [ignore] */
	struct server_id server_id;
	uint32_t open_global_id;
	uint64_t open_persistent_id;
	uint64_t open_volatile_id;
	struct dom_sid open_owner;
	NTTIME open_time;
	struct GUID create_guid;
	struct GUID client_guid;
	struct GUID app_instance_id;
	NTTIME disconnect_time;
	uint32_t durable_timeout_msec;
	uint8_t durable;
	DATA_BLOB backend_cookie;
	uint64_t channel_sequence;
};

union smbXsrv_open_globalU {
	struct smbXsrv_open_global0 *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_open_globalB {
	enum smbXsrv_version_values version;
	uint32_t seqnum;
	union smbXsrv_open_globalU info;/* [switch_is(version)] */
}/* [public] */;

struct smbXsrv_open {
	struct smbXsrv_open_table *table;/* [ignore] */
	struct db_record *db_rec;/* [ignore] */
	uint32_t local_id;
	struct smbXsrv_open_global0 *global;/* [ref] */
	NTSTATUS status;
	NTTIME idle_time;
	struct files_struct *compat;/* [ignore] */
	uint8_t flags;
	uint32_t create_action;
	uint64_t request_count;
	uint64_t pre_request_count;
};

union smbXsrv_openU {
	struct smbXsrv_open *info0;/* [case(0),unique] */
	uint64_t *dummy;/* [default,unique] */
};

struct smbXsrv_openB {
	enum smbXsrv_version_values version;
	uint32_t reserved;/* [value(0)] */
	union smbXsrv_openU info;/* [switch_is(version)] */
}/* [public] */;


struct smbXsrv_version_global_decode {
	struct {
		struct smbXsrv_version_globalB blob;
	} in;

};


struct smbXsrv_client_global_decode {
	struct {
		struct smbXsrv_client_globalB blob;
	} in;

};


struct smbXsrv_client_decode {
	struct {
		struct smbXsrv_clientB blob;
	} in;

};


struct smbXsrv_connection_pass_decode {
	struct {
		struct smbXsrv_connection_passB blob;
	} in;

};


struct smbXsrv_session_global_decode {
	struct {
		struct smbXsrv_session_globalB blob;
	} in;

};


struct smbXsrv_session_decode {
	struct {
		struct smbXsrv_sessionB blob;
	} in;

};


struct smbXsrv_session_close_decode {
	struct {
		struct smbXsrv_session_closeB blob;
	} in;

};


struct smbXsrv_tcon_global_decode {
	struct {
		struct smbXsrv_tcon_globalB blob;
	} in;

};


struct smbXsrv_tcon_decode {
	struct {
		struct smbXsrv_tconB blob;
	} in;

};


struct smbXsrv_open_global_decode {
	struct {
		struct smbXsrv_open_globalB blob;
	} in;

};


struct smbXsrv_open_decode {
	struct {
		struct smbXsrv_openB blob;
	} in;

};

#endif /* _HEADER_smbXsrv */
#endif /* _PIDL_HEADER_smbXsrv */
