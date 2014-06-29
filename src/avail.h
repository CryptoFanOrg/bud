#ifndef SRC_AVAIL_H_
#define SRC_AVAIL_H_

#include "uv.h"

#include "client-common.h"
#include "config.h"

/* Forward declarations */
struct bud_client_s;

bud_config_backend_t* bud_select_backend(bud_config_t* config,
                                         bud_config_balance_t balance,
                                         bud_config_backend_list_t* backend);

/* Client helpers */
bud_client_error_t bud_client_connect(struct bud_client_s* client);
void bud_client_connect_cb(uv_connect_t* req, int status);
void bud_client_connect_close_cb(uv_handle_t* handle);
bud_client_error_t bud_client_retry(struct bud_client_s* client);
void bud_client_retry_cb(uv_timer_t* timer);

#endif  /* SRC_AVAIL_H_ */
