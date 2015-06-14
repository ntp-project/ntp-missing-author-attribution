#include "config.h"
#include "ntp_stdlib.h"
#include "vint64ops.h"
#include "unity.h"

void
test_ParseVUI64_pos(void) {
	vint64 act, exp;
	const char *sp;
	char       *ep;

	sp         = "1234x";
	exp.D_s.hi = 0;
	exp.D_s.lo = 1234;
	act        = strtouv64(sp, &ep, 0);

	TEST_ASSERT_EQUAL(exp.D_s.hi, act.D_s.hi);
	TEST_ASSERT_EQUAL(exp.D_s.lo, act.D_s.lo);
	TEST_ASSERT_EQUAL(*ep, 'x');
}

void
test_ParseVUI64_neg(void) {
	vint64 act, exp;
	const char *sp;
	char       *ep;

	sp         = "-1234x";
	exp.D_s.hi = ~0;
	exp.D_s.lo = -1234;
	act        = strtouv64(sp, &ep, 0);

	TEST_ASSERT_EQUAL(exp.D_s.hi, act.D_s.hi);
	TEST_ASSERT_EQUAL(exp.D_s.lo, act.D_s.lo);
	TEST_ASSERT_EQUAL(*ep, 'x');
}

void
test_ParseVUI64_case(void) {
	vint64 act, exp;
	const char *sp;
	char       *ep;

	sp         = "0123456789AbCdEf";
	exp.D_s.hi = 0x01234567;
	exp.D_s.lo = 0x89ABCDEF;
	act        = strtouv64(sp, &ep, 16);

	TEST_ASSERT_EQUAL(exp.D_s.hi, act.D_s.hi);
	TEST_ASSERT_EQUAL(exp.D_s.lo, act.D_s.lo);
	TEST_ASSERT_EQUAL(*ep, '\0');
}
