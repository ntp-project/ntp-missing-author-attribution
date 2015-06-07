#include "testcalshims.h"

/* This file contains various constants that libntp needs to be set
 *  and that is normally defined in ntpd/ntpq/...
 */

u_long current_time = 4; // needed by authkeys. Used only in to calculate lifetime.
const char *progname = "libntptest";

//static //should be static in c 
static time_t nowtime = 0;


time_t timefunc(time_t *ptr)
{
    if (ptr)
	*ptr = nowtime;
    return nowtime;
}


//commented out cuz it was causing problems for a_md5encrypt.c

void settime(int y, int m, int d, int H, int M, int S)
{
    time_t days(ntpcal_edate_to_eradays(y-1, m-1, d-1) + 1 - DAY_UNIX_STARTS);
    time_t secs(ntpcal_etime_to_seconds(H, M, S));

    nowtime = days * SECSPERDAY + secs;
}

