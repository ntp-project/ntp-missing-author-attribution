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

void test_keywordIncorrectToken(void){
	char * temp = keyword(999);
	printf("%s",temp);
}

void test_keywordServerToken(void){
	char * temp = keyword(401);
	printf("%s",temp); //143 or 401 ?

}
