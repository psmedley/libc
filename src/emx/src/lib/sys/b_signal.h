/* $Id: b_signal.h 1646 2004-11-17 09:12:37Z bird $ */
/** @file
 *
 * InnoTek LIBC - Signal Internals.
 *
 * Copyright (c) 2004 knut st. osmundsen <bird-srcspam@anduin.net>
 *
 *
 * This file is part of InnoTek LIBC.
 *
 * InnoTek LIBC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * InnoTek LIBC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with InnoTek LIBC; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __signals_h__
#define __signals_h__

#include <sys/cdefs.h>
#include <signal.h>
#include <InnoTekLIBC/libc.h>
#include <InnoTekLIBC/backend.h>
#include <InnoTekLIBC/sharedpm.h>

/** Signal set for the signals which are pending on a process scope.
 * These signals are blocked by all threads and waiting to be delivered
 * to a thread. */
extern sigset_t     __libc_gSignalPending;


__BEGIN_DECLS

int         __libc_back_signalInit(void);
int         __libc_back_signalInitExe(void *pvRegRec);
int         __libc_back_signalSemRequest(void);
void        __libc_back_signalSemRelease(void);
unsigned    __libc_back_signalSemIsOwner(void);
void        __libc_back_signalPokeThread(__LIBC_PTHREAD pThrd);
void        __libc_back_signalPokeProcess(void);
int         __libc_back_signalReschedule(__LIBC_PTHREAD pThrd);
int         __libc_back_signalQueueSelf(int iSignalNo, siginfo_t *pSigInfo);
int         __libc_back_signalSuspend(void);
int         __libc_back_signalAccept(__LIBC_PTHREAD pThrd, int iSignalNo, sigset_t *pSigSet, siginfo_t *pSigInfo);
int         __libc_back_signalWait(__LIBC_PTHREAD pThrd, volatile int *pfDone, const struct timespec *pTimeout);
int         __libc_back_signalSendPidOther(pid_t pid, int iSignalNo, const siginfo_t *pSigInfo);
int         __libc_back_signalAction(int iSignalNo, const struct sigaction *pSigAct, struct sigaction *pSigActOld);
int         __libc_back_signalRaisePoked(void *pvXcptParams, int tidPoker);
void        __libc_back_signalOS2V1Handler16bit(unsigned short uSignal, unsigned short uArg);
void        __libc_back_signalOS2V1Handler32bit(unsigned uSignal, unsigned uArg);
int         __libc_back_signalInheritPack(__LIBC_PSPMINHSIG *ppSig, size_t *pcbSig);
void        __libc_back_signalTimerNotifyTerm(void);
int         __libc_back_signalRaiseInternal(__LIBC_PTHREAD pThrd, int iSignalNo, const siginfo_t *pSigInfo, void *pvQueued, unsigned fFlags);


__END_DECLS

#endif
