#include "test-libntp.h"
#include <stdio.h>	/* HMS: for the printf's below */

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
