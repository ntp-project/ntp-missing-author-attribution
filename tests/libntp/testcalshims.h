//#include "tests_main.h"
#include "config.h"

#include "ntp_stdlib.h"
#include "ntp_calendar.h"

//u_long current_time = 4; // needed by authkeys. Used only in to calculate lifetime.
//const char *progname = "libntptest";

static time_t timefunc(time_t*);
static time_t nowtime;
static void   settime(int y, int m, int d, int H, int M, int S);

