/* execl.c (emx+gcc) -- Copyright (c) 1992-1995 by Eberhard Mattes */

#include "libc-alias.h"
#include <stddef.h>
#include <stdarg.h>
#include <process.h>
#define __LIBC_LOG_GROUP __LIBC_LOG_GRP_PROCESS
#include <InnoTekLIBC/logstrict.h>

int _STD(execl) (const char *name, const char *arg0, ...)
{
    LIBCLOG_ENTER("name=%s arg0=%s ...\n", name, arg0);
    int result;

    /* Note: Passing `arg0' to spawnv() is not portable. */

    result = spawnv(P_OVERLAY, name, (char * const *) &arg0);
    LIBCLOG_ERROR_RETURN_INT(result);
}
