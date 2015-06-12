#include "bug-2803.h"
#include "unity.h"


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
void test_main( void )
{
	TEST_ASSERT_EQUAL(0, main2());
}
