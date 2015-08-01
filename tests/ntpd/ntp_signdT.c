#include "config.h"

#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_stdlib.h"

#include "unity.h"

#include "test-libntp.h"

#define HAVE_NTP_SIGND

#include "ntp_signd.c"

//extern int ux_socket_connect(const char *name);


void 
test_ux_socket_connect(void){

//send_via_ntp_signd(NULL,NULL,NULL,NULL,NULL);	
	/*
	send_via_ntp_signd(
	struct recvbuf *rbufp,	
	int	xmode,
	keyid_t	xkeyid, 
	int flags,
	struct pkt  *xpkt)
*/
	TEST_ASSERT_EQUAL(-1, ux_socket_connect(NULL));
	//TEST_ASSERT_EQUAL(-1, ux_socket_connect("127.0.0.1:123"));
	TEST_ASSERT_EQUAL(-1, ux_socket_connect("/socket"));

	//write_all()
	char *socketName = "Random_Socket_Name";
	int length = strlen(socketName);

}

void
test_write_all(void){

}
