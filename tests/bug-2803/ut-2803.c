#include "bug-2803.h"
#include "unity.h"

#define VERSION 3 //change this to 5 and the test wont fail.


void setUp(void)
{
  
}

void tearDown(void)
{
}

/*
int main( void )
{

	// loop from {0.0} to {1.1000000} stepping by tv_sec by 1 and tv_usec by 100000
	test_loop( 0, 0,   1,  MICROSECONDS,   1,  MICROSECONDS / 10 );

	// test_loop( 0, 0,   5,  MICROSECONDS,   1,  MICROSECONDS / 1000 );
	// test_loop( 0, 0,  -5, -MICROSECONDS,  -1, -MICROSECONDS / 1000 );

	return 0;
}
*/
int test_main( void )
{
	TEST_ASSERT_EQUAL(0, main2());
}

void test_custom(void)
{	
	if(VERSION < 4 ){	
		TEST_FAIL_MESSAGE("expected to fail");
	}

	else TEST_ASSERT_EQUAL(1,1);
}
