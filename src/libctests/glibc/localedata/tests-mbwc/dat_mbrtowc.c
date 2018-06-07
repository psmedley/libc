/*
 *  TEST SUITE FOR MB/WC FUNCTIONS IN C LIBRARY
 *
 *	 FILE:	dat_mbrtowc.c
 *
 *	 MBTOWC:  size_t mbrtowc (wchar_t *pwc, char *s, size_t n,
 *				  mbstate_t *ps);
 */

#include <limits.h>

/* Note:
	assumes	 en_US = en_US.ascii
*/




TST_MBRTOWC tst_mbrtowc_loc [] = {
  {
    { Tmbrtowc, TST_LOC_de },
    {
      { /*----------------- #01 -----------------*/
	{
	  {
	    { 1, 1, "���",	   1,		 0, 0 },
	    { 1, 1, "���",	   2,		 0, 0 },
	    { 1, 1, "���",	   USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { /*----------------- #02 -----------------*/
	{
	  {
	    { 1, 1, "���",	    1,		  0, 0 },
	    { 1, 1, "���",	    2,		  0, 0 },
	    { 1, 1, "���",	    USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { .is_last = 1 }
    }
  },
#if 0
  /* XXX: These tests don't make sense to me.  */
  {
    { Tmbrtowc, TST_LOC_enUS },
    {
      { /*----------------- #01 -----------------*/
	{
	  {
	    { 1, 1, "���",	    1,		  0, 0 },
	    { 1, 1, "���",	    2,		  0, 0 },
	    { 1, 1, "���",	    USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { /*----------------- #02 -----------------*/
	{
	  {
	    { 1, 1, "���",	    1,		  0, 0 },
	    { 1, 1, "���",	    2,		  0, 0 },
	    { 1, 1, "���",	    USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { .is_last = 1 }
    }
  },
  {
    { Tmbrtowc, TST_LOC_eucJP },
    {
      { /*----------------- #01 -----------------*/
	{
	  {
	    { 1, 1, "���",	    1,		  0, 0 },
	    { 1, 1, "���",	    2,		  0, 0 },
	    { 1, 1, "���",	    USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { /*----------------- #02 -----------------*/
	{
	  {
	    { 1, 1, "���",	    1,		  0, 0 },
	    { 1, 1, "���",	    2,		  0, 0 },
	    { 1, 1, "���",	    USE_MBCURMAX, 0, 0 },
	  }
	},
	{
	  {
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	    { 0,  1,  1,   0x00C4 },
	  }
	}
      },
      { .is_last = 1 }
    }
  },
#endif
  {
    { Tmbrtowc, TST_LOC_end }
  }
};
