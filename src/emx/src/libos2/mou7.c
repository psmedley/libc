/* mou7.c */

#define INCL_MOU
#include <os2.h>

USHORT _THUNK_FUNCTION (Mou16FlushQue) ();

USHORT MouFlushQue (HMOU hmou)
{
  return ((USHORT)
          (_THUNK_PROLOG (2);
           _THUNK_SHORT (hmou);
           _THUNK_CALL (Mou16FlushQue)));
}
