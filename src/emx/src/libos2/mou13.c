/* mou13.c */

#define INCL_MOU
#include <os2.h>

USHORT _THUNK_FUNCTION (Mou16GetNumQueEl) ();

USHORT MouGetNumQueEl (PMOUQUEINFO qmouqi, HMOU hmou)
{
  return ((USHORT)
          (_THUNK_PROLOG (4+2);
           _THUNK_FLAT (qmouqi);
           _THUNK_SHORT (hmou);
           _THUNK_CALL (Mou16GetNumQueEl)));
}
