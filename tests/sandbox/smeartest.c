#include <config.h>

#include <ntp.h>
#include <ntp_fp.h>

/*
 * we want to test a refid format of:
 * 254.x.y.x
 *
 * where x.y.z are 24 bits containing 2 (signed) integer bits
 * and 22 fractional bits.
 *
 * we want functions to convert to/from this format, with unit tests.
 *
 * Interesting test cases include:
 * 254.0.0.0
 * 254.0.0.1
 * 254.127.255.255
 * 254.128.0.0
 * 254.255.255.255
 */

char *progname = "";

l_fp convertRefIDToLFP(uint32_t r);
uint32_t convertLFPToRefID(l_fp num);


/*
 * The smear data in the refid is the bottom 3 bytes of the refid,
 * 2 bits of integer
 * 22 bits of fraction
 */
l_fp
convertRefIDToLFP(uint32_t r)
{
	l_fp temp;

	printf("%02x %02x %02x %x: ",
		(r >> 22) & 0x3,
		(r >> 14) & 0xff,
		(r >>  6) & 0xff,
		(r & 0x0f)
		);

	temp.l_ui = (r >> 22) & 0x3;
	temp.l_uf = ((uint32_t) ((r & 0x003FC000) << 10))
		  | ((uint32_t) ((r & 0x00003FC0) << 10))
		  | ((uint32_t) ((r & 0x0000003F) << 10));

	if (temp.l_ui & 2)
		temp.l_ui |= 0xFFFFFFFEu;

	return temp;
}


uint32_t
convertLFPToRefID(l_fp num) //unfinished
{
	uint32_t temp;

	temp  = (uint8_t) (num.l_ui << 6) | (num.l_uf >> 26);
	temp |= (uint8_t) (num.l_uf >> 18); //should I add & 0x?? here or are only the lowest bits taken to unint8_t?
	temp |= (uint8_t) (num.l_uf >> 10);

	printf("%02x %02x %02x %x: ",
		(temp >> 22) & 0x3,
		(temp >> 14) & 0xff,
		(temp >>  6) & 0xff,
		(temp & 0x0f)
		);

	return temp;
}


//void rtol(uint32_t r);

l_fp 
rtol(uint32_t r)
{
	l_fp l;

	// l = convertRefIDToLFP(htonl(r));
	l = convertRefIDToLFP(r);
	printf("refid %#x, smear %s\n", r, lfptoa(&l, 8));

	return l;
}

uint32_t
ltor(l_fp l)
{
	uint32_t r;

	// l = convertRefIDToLFP(htonl(r));
	r = convertLFPToRefID(l);
	printf("refid %#x, smear %s\n", r, lfptoa(&l, 8));

	return r;
}


main()
{

	l_fp test1 =	rtol(0xfe800000);
	l_fp test2=	rtol(0xfe800001);
	l_fp test3 =	rtol(0xfe8ffffe);
	l_fp test4 =	rtol(0xfe8fffff);
	l_fp test6 = 	rtol(0xfef00000);
	l_fp test7 =	rtol(0xfef00001);
	l_fp test8 =	rtol(0xfefffffe);
	l_fp test9 =	rtol(0xfeffffff);

	l_fp test10 =	rtol(0xfe000000);
	l_fp test11 =	rtol(0xfe000001);
	l_fp test12 =	rtol(0xfe5ffffe);
	l_fp test13 =	rtol(0xfe5fffff);
	l_fp test14 =	rtol(0xfe6ffffe);
	l_fp test15 =	rtol(0xfe6fffff);
	l_fp test16 =	rtol(0xfe700000);
	l_fp test17 =	rtol(0xfe700001);
	l_fp test18 =	rtol(0xfe7ffffe);
	l_fp test19 =	rtol(0xfe7fffff);

	printf("\n\n");

	ltor(test1);
	ltor(test2);
	ltor(test3);
	ltor(test4);
	ltor(test6);
	ltor(test7);
	ltor(test8);
	ltor(test9);

	ltor(test10);
	ltor(test11);
	ltor(test12);
	ltor(test13);
	ltor(test14);
	ltor(test15);
	ltor(test16);
	ltor(test17);
	ltor(test18);
	ltor(test19);

	return 0;
}
