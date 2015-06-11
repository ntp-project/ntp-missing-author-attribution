#include <config.h>

#include "ntp_stdlib.h"
#include "ntp_calendar.h"
#include "test-libntp.h"

const char *progname = "test-libntp";

// current_time is needed by authkeys. Used only in to calculate lifetime.
u_long current_time = 4;

void
setUp(void)
{
	printf("setUp from big test");
}

void
tearDown(void)
{
}

void
test_modetoa(void)
{
printf("modetoa:test_KnownMode()\n");
	test_KnownMode();
printf("modetoa:test_UnknownMode()\n");
	test_UnknownMode();
}

void
test_uglydate(void)
{
printf("uglydate:test_ConstantDateTime()\n");
	test_ConstantDateTime();
}
