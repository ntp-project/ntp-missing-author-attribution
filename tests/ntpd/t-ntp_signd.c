#include "config.h"

#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_stdlib.h"

#include "unity.h"

#include "test-libntp.h"

#define HAVE_NTP_SIGND

#include "ntp_signd.c"

extern int ux_socket_connect(const char *name);


//this connect function overrides/mocks connect() from  <sys/socket.h>
int connect(int socket, const struct sockaddr *address,
socklen_t address_len){
	return 1;
}

int isGE(int a,int b){ 
	if(a >= b) {return 1;}
	else {return 0;}
}


void 
test_connect_incorrect_socket(void){
	TEST_ASSERT_EQUAL(-1, ux_socket_connect(NULL));
}

void 
test_connect_correct_socket(void){

//send_via_ntp_signd(NULL,NULL,NULL,NULL,NULL);	
	/*
	send_via_ntp_signd(
	struct recvbuf *rbufp,	
	int	xmode,
	keyid_t	xkeyid, 
	int flags,
	struct pkt  *xpkt)
*/
	
	int temp = ux_socket_connect("/socket");

	//risky, what if something is listening on :123, or localhost isnt 127.0.0.1?
	//TEST_ASSERT_EQUAL(-1, ux_socket_connect("127.0.0.1:123")); 

	//printf("%d\n",temp);
	TEST_ASSERT_TRUE(isGE(temp,0));

	//write_all();
	//char *socketName = "Random_Socket_Name";
	//int length = strlen(socketName);

}



void
test_write_all(void){

}
