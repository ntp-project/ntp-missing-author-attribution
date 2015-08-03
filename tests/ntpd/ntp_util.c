#include "config.h"

#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_stdlib.h"

#include "unity.h"
#include "test-libntp.h"

#include <time.h>
#include <string.h>

void test_mprintf_clock_stats(void){
	char *one = "this";
	char *two = "is";
	char *three = "becoming a string";

	int ret_value1 = mprintf_clock_stats(NULL, "%s", one) ;
	int ret_value2 = mprintf_clock_stats(NULL, "%s %s %s", one, two, three) ;

	TEST_ASSERT_EQUAL( strlen(one),  ret_value1);
	TEST_ASSERT_EQUAL(25, ret_value2);

}


void test_fstostr(void){
	u_int32 ntp;
	char *buf ;

	ntp = 0;
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602070628", buf);
	//The output format of function fstostr() is : YYYY-MM-DD-HH-MI 
	//[ Year-Month-MonthDay-Hour-Minute ]

	ntp += 60;  //Increment by 60 secs ie 1 minute
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602070629", buf);

	ntp += 60;  //Increment by 60 secs ie 1 minute
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602070630", buf);

	ntp += 3600;  //Increment by 3600 secs ie 1 hour 
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602070730", buf);

	ntp += 3600;  //Increment by 3600 secs ie 1 hour 
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602070830", buf);

	ntp += (24*60*60);  //Increment by 1 day 
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602080830", buf);

	ntp += (24*60*60);  //Increment by 1 day
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602090830", buf);
	
	ntp += (10*24*60*60);  //Increment by 10 days
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203602190830", buf);

	ntp += (12*24*60*60);  //Increment by 12 days
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203603020830", buf);

	ntp += (31*24*60*60);  //Increment by 1 month
	buf = fstostr(ntp); 
	TEST_ASSERT_EQUAL_STRING("203604020830", buf);
	
}

