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

	r = ntohl(r);

	printf("%03d %08x: ", (r >> 24) & 0xFF, (r & 0x00FFFFFF) );

	temp.l_uf = (r << 10);	/* 22 fractional bits */

	temp.l_ui = (r >> 22) & 0x3;
	temp.l_ui |= ~(temp.l_ui & 2) + 1;

	return temp;
}


uint32_t
convertLFPToRefID(l_fp num)
{
	uint32_t temp;

	/* round the input with the highest bit to shift out from the
	 * fraction, then keep just two bits from the integral part.
	 *
	 * TODO: check for overflows; should we clamp/saturate or just
	 * complain?
	 */
	L_ADDUF(&num, 0x200);
	num.l_ui &= 3;

	/* combine integral and fractional part to 24 bits */
	temp  = (num.l_ui << 22) | (num.l_uf >> 10);

	/* put in the leading 254.0.0.0 */
	temp |= UINT32_C(0xFE000000);

	printf("%03d %08x: ", (temp >> 24) & 0xFF, (temp & 0x00FFFFFF) );

	return temp;
}

/* Tests start here */

void rtol(uint32_t r);

void
rtol(uint32_t r)
{
	l_fp l;

	printf("rtol: ");

	l = convertRefIDToLFP(htonl(r));
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
