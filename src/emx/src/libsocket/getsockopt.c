/* $Id: getsockopt.c 1517 2004-09-19 15:53:31Z bird $ */
/** @file
 *
 * getsockopt().
 *
 * Copyright (c) 2003 knut st. osmundsen <bird-srcspam@anduin.net>
 *
 *
 * This file is part of Innotek LIBC.
 *
 * Innotek LIBC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Innotek LIBC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Innotek LIBC; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#include "libc-alias.h"
#include <errno.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <emx/io.h>
#define __LIBC_LOG_GROUP __LIBC_LOG_GRP_SOCKET
#include <InnoTekLIBC/logstrict.h>
#include "socket.h"

int getsockopt(int socket, int level, int optname, void *optval, int *optlen)
{
    LIBCLOG_ENTER("socket=%d level=%#x optname=%#x optval=%p optlen=%p\n",
                  socket, level, optname, (void *)optval, (void *)optlen);
    PLIBCSOCKETFH   pFHSocket = __libc_TcpipFH(socket);
    if (pFHSocket)
    {
        int rc;
        rc = __libsocket_getsockopt(pFHSocket->iSocket, level, optname, optval, optlen);
        if (rc >= 0)
        {
            switch (level)
            {
                case SOL_SOCKET:
                    switch (optname)
                    {
                        case SO_ERROR:
                        {
                            int err = *(int*)optval;
                            if (err >= EOS2_TCPIP_OFFSET && err < EOS2_TCPIP_OFFSET + 1000)
                            {
                                err -= EOS2_TCPIP_OFFSET;
                                *(int*)optval = err;
                            }
                            LIBCLOG_MSG("err: %d\n", err);
                            break;
                        }
                    }
                    break;
            }
            LIBCLOG_RETURN_INT(rc);
        }
        __libc_TcpipUpdateErrno();
    }

    LIBCLOG_RETURN_INT(-1);
}


