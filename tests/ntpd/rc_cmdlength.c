#include "config.h"

#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_stdlib.h"

#include "unity.h"

#include <string.h>

#include "test-libntp.h"


void
test_EvaluateCommandLength(void){
	const char *src_buf = "This is random command";
	const char *src_end = "This is random command";

	size_t commandLength = remoteconfig_cmdlength(src_buf, src_end);

	TEST_ASSERT_EQUAL(strlen(src_buf), commandLength );
}
