#ifndef __hustdb_ha_write_handler_20150730104912_h__
#define __hustdb_ha_write_handler_20150730104912_h__

#include "hustdb_ha_handler_base.h"

#define HUSTDB_METHOD_PUT        1
#define HUSTDB_METHOD_DEL        2
#define HUSTDB_METHOD_HSET       3
#define HUSTDB_METHOD_HDEL       4
#define HUSTDB_METHOD_SADD       5
#define HUSTDB_METHOD_SREM       6
#define HUSTDB_METHOD_ZADD       7
#define HUSTDB_METHOD_ZREM       8

ngx_bool_t hustdb_ha_has_tb(ngx_str_t * backend_uri, ngx_http_request_t *r);
ngx_bool_t hustdb_ha_has_ttl(ngx_str_t * backend_uri, ngx_http_request_t *r);
ngx_bool_t hustdb_ha_check_incr(ngx_str_t * backend_uri, ngx_http_request_t *r);

typedef ngx_int_t (*hustdb_ha_start_write_t)(
    ngx_bool_t support_post_only,
    ngx_bool_t key_in_body,
    ngx_bool_t has_tb,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

ngx_int_t hustdb_ha_start_post(
    ngx_bool_t support_post_only,
    ngx_bool_t key_in_body,
    ngx_bool_t has_tb,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);
ngx_int_t hustdb_ha_start_del(
    ngx_bool_t support_post_only,
    ngx_bool_t key_in_body,
    ngx_bool_t has_tb,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

ngx_int_t hustdb_ha_write_handler(
    uint8_t method,
    ngx_bool_t support_post_only,
    ngx_bool_t key_in_body,
    ngx_bool_t has_tb,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r,
    hustdb_ha_start_write_t start_write);

ngx_int_t hustdb_ha_zwrite_handler(
    uint8_t method,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

ngx_int_t hustdb_ha_write_cache_handler(
    hustdb_ha_check_parameter_t check,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

#endif // __hustdb_ha_write_handler_20150730104912_h__
