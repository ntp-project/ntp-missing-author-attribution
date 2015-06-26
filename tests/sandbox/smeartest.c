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
	temp.l_uf = ((uint32_t) ((r >> 14) & 0xFF) << 26)
		  | ((uint32_t) ((r >>  6) & 0xFF) << 18)
		  | ((uint32_t) ((r >>  0) & 0x0F) << 10);

	if (temp.l_ui & 2)
		temp.l_ui |= 0xFFFFFFFEu;

	return temp;
}


uint32_t
convertLFPToRefID(l_fp num)
{
	uint32_t temp;

	temp  = (uint8_t) (num.l_ui << 6) | (num.l_uf >> 26);
	temp |= (uint8_t) (num.l_uf >> 18);
	temp |= (uint8_t) (num.l_uf >> 10);

	return temp;
}


void rtol(uint32_t r);

void
rtol(uint32_t r)
{
	l_fp l;

	// l = convertRefIDToLFP(htonl(r));
	l = convertRefIDToLFP(r);
	printf("refid %#x, smear %s\n", r, lfptoa(&l, 8));

	return;
}


main()
{

	rtol(0xfe800000);
	rtol(0xfe800001);
	rtol(0xfe8ffffe);
	rtol(0xfe8fffff);
	rtol(0xfef00000);
	rtol(0xfef00001);
	rtol(0xfefffffe);
	rtol(0xfeffffff);

	rtol(0xfe000000);
	rtol(0xfe000001);
	rtol(0xfe6ffffe);
	rtol(0xfe6fffff);
	rtol(0xfe700000);
	rtol(0xfe700001);
	rtol(0xfe7ffffe);
	rtol(0xfe7fffff);

	return 0;
}
