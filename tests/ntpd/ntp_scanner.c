#include "config.h"

#include "unity.h"

//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>

//#include "ntpd.h"
//#include "ntp_config.h"
//#include "ntpsim.h"
#include "ntp_scanner.h"
//#include "ntp_parser.h"


/* ntp_keyword.h declares finite state machine and token text */
//#include "ntp_keyword.h"

void test_keywordIncorrectToken(void);
void test_keywordServerToken(void);
void test_DropUninitializedStack(void);
void test_IncorrectlyInitializeLexStack(void);
void test_InitializeLexStack(void);


void test_keywordIncorrectToken(void){
	char * temp = keyword(999);
	//printf("%s\n",temp);
	TEST_ASSERT_EQUAL_STRING("(keyword not found)",temp);
}

void test_keywordServerToken(void){
	char * temp = keyword(401);
	//printf("%s",temp); //143 or 401 ?
	TEST_ASSERT_EQUAL_STRING("server",temp);
}

void test_DropUninitializedStack(void){
	lex_drop_stack();
}

void test_IncorrectlyInitializeLexStack(void){

	TEST_ASSERT_FALSE(lex_init_stack(NULL,NULL));
	lex_drop_stack();
}

void test_InitializeLexStack(void){
	
	//Some sort of server is required for this to work.
	sockaddr_u *	remote_addr;
	char origin[128] ={ "" } ;
	strcat(origin,"127.0.0.1");
	//snprintf(origin, sizeof(origin), "remote config from %s", stoa(remote_addr));
	TEST_ASSERT_TRUE(lex_init_stack(origin,NULL)); //path, mode -> NULL is ok!
	lex_drop_stack();
}

void test_PopEmptyStack(void){
	int temp = lex_pop_file();

	TEST_ASSERT_FALSE(temp);
}
