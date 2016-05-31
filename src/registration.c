#include "connection.h"
#include "conversions.h"
#include "subscribe.h"
#include <R_ext/Rdynload.h>

static const R_CallMethodDef callMethods[] = {
  {"Credux_redis_connect",       (DL_FUNC) &redux_redis_connect,        2},
  {"Credux_redis_connect_unix",  (DL_FUNC) &redux_redis_connect_unix,   1},

  {"Credux_redis_command",       (DL_FUNC) &redux_redis_command,        2},

  {"Credux_redis_pipeline",      (DL_FUNC) &redux_redis_pipeline,       2},

  {"Credux_redis_subscribe",     (DL_FUNC) &redux_redis_subscribe,      5},
  {"Credux_redis_unsubscribe",   (DL_FUNC) &redux_redis_unsubscribe,    3},

  {NULL,                         NULL,                                  0}
};

void R_init_redux(DllInfo *info) {
#ifdef _WIN32
  // This is needed to ensure that the windows socket library is
  // correctly initialised, otherwise a socket error will occur.
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
}
