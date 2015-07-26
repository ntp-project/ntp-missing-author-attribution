#include "config.h"

#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_stdlib.h"

#include "unity.h"

#include "test-libntp.h"


void 
test_ux_socket_connect(void){
	TEST_ASSERT_EQUAL(-1, ux_socket_connect(NULL));


	//write_all()
	char *socketName = "Random_Socket_Name";
	int length = strlen(socketName);

}

void
test_write_all(void)
