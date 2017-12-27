// Last Update:2017-12-27 23:11:07
/**
 * @file merror.h
 * @brief 
 * @author luxueqian
 * @version 0.1.00
 * @date 2017-12-27
 */

#ifndef MERROR_H
#define MERROR_H
#include "common.h"
#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif

void err_ret(const char * fmt, ...);
void err_sys(const char * fmt, ...);
void err_dump(const char * fmt, ...);
void err_msg(const char * fmt, ...);
void err_quit(const char * fmt, ...);

#ifdef __cplusplus
}
#endif
#endif  /*MERROR_H*/
