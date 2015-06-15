#include "config.h"
#include "ntp_stdlib.h"
#include "ntp_calendar.h"
#include "unity.h"
#include "c_lfptest.h"

static const int32 HALF = -2147483647L - 1L;
static const int32 HALF_PROMILLE_UP = 2147484; // slightly more than 0.0005
static const int32 HALF_PROMILLE_DOWN = 2147483; // slightly less than 0.0005
static const int32 QUARTER = 1073741824L;
static const int32 QUARTER_PROMILLE_APPRX = 1073742L;



void test_PositiveInteger(void) {
	const char *str = "00001000.00000000";
	l_fp actual;

	l_fp expected = {4096, 0}; // 16^3, no fraction part.

	TEST_ASSERT_TRUE(hextolfp(str, &actual));
	TEST_ASSERT_TRUE(IsEqual(expected, actual));
}

void test_NegativeInteger(void) {
	const char *str = "ffffffff.00000000"; // -1 decimal
	l_fp actual;

	l_fp expected = {-1, 0};

	TEST_ASSERT_TRUE(hextolfp(str, &actual));
	TEST_ASSERT_TRUE(IsEqual(expected, actual));
}

void test_PositiveFraction(void) {
	const char *str = "00002000.80000000"; // 8196.5 decimal
	l_fp actual;

	l_fp expected = {8192, HALF};

	TEST_ASSERT_TRUE(hextolfp(str, &actual));
	TEST_ASSERT_TRUE(IsEqual(expected, actual));
}

void test_NegativeFraction(void) {
	const char *str = "ffffffff.40000000"; // -1 + 0.25 decimal
	l_fp actual;

	l_fp expected = {-1, QUARTER}; //-1 + 0.25

	TEST_ASSERT_TRUE(hextolfp(str, &actual));
	TEST_ASSERT_TRUE(IsEqual(expected, actual));
}

void test_IllegalNumberOfInteger(void) {
	const char *str = "1000000.00000000"; // Missing one digit in integral part.
	l_fp actual;

	TEST_ASSERT_FALSE(hextolfp(str, &actual));
}

void test_IllegalChar(void) {
	const char *str = "10000000.0000h000"; // Illegal character h.
	l_fp actual;

	TEST_ASSERT_FALSE(hextolfp(str, &actual));
}

