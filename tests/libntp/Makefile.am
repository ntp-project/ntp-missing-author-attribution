NULL =
BUILT_SOURCES =
CLEANFILES =

run_unity =	cd $(srcdir) && ruby ../../sntp/unity/auto/generate_test_runner.rb

#removed test-libntp
check_PROGRAMS = test-modetoa test-uglydate
if GTEST_AVAILABLE
check_PROGRAMS += tests
else
EXTRA_PROGRAMS = tests
endif

LDADD =					\
	$(top_builddir)/libntp/libntp.a	\
	$(LDADD_LIBNTP)			\
	$(PTHREAD_LIBS)			\
	$(LDADD_NTP)			\
	$(NULL)

tests_LDADD =				\
	$(LDADD)			\
	$(GTEST_LDFLAGS)		\
	$(GTEST_LIBS)			\
	$(NULL)

AM_CFLAGS   = $(CFLAGS_NTP)
AM_CXXFLAGS = $(GTEST_CXXFLAGS)

AM_CPPFLAGS  = $(NTP_INCS)
AM_CPPFLAGS += -I$(top_srcdir)/sntp
AM_CPPFLAGS += $(GTEST_CPPFLAGS)
AM_CPPFLAGS += $(CPPFLAGS_NTP)

AM_LDFLAGS = $(LDFLAGS_NTP)

tests_SOURCES = $(top_srcdir)/sntp/tests_main.cpp	\
		libntptest.cpp		\
		a_md5encrypt.cpp	\
		atoint.cpp		\
		atouint.cpp		\
		authkeys.cpp		\
		buftvtots.cpp		\
		calendar.cpp		\
		caljulian.cpp		\
		caltontp.cpp		\
		calyearstart.cpp	\
		clocktime.cpp		\
		decodenetnum.cpp	\
		hextoint.cpp		\
		hextolfp.cpp		\
		humandate.cpp		\
		lfpfunc.cpp		\
		lfptostr.cpp		\
		g_modetoa.cpp		\
		msyslog.cpp		\
		netof.cpp		\
		numtoa.cpp		\
		numtohost.cpp		\
		octtoint.cpp		\
		prettydate.cpp		\
		recvbuff.cpp		\
		refnumtoa.cpp		\
		sfptostr.cpp		\
		socktoa.cpp		\
		ssl_init.cpp		\
		statestr.cpp		\
		strtolfp.cpp		\
		timespecops.cpp		\
		timestructs.cpp		\
		timevalops.cpp		\
		tstotv.cpp		\
		tvtots.cpp		\
		g_uglydate.cpp		\
		vi64ops.cpp		\
		ymd2yd.cpp		\
		$(NULL)

noinst_HEADERS =	\
	lfptest.h	\
	libntptest.h	\
	sockaddrtest.h	\
	timestructs.h	\
	$(NULL)

#$(srcdir)/run-test-libntp.c: $(srcdir)/test-libntp.c $(std_unity_list)
#	$(run_unity) test-libntp.c run-test-libntp.c

#test_libntp_CFLAGS = 			\
#	-I$(top_srcdir)/sntp/unity	\
#	$(NULL)

#test_libntp_LDADD =  				\
#	$(LDADD)				\
#	$(top_builddir)/sntp/unity/libunity.a	\
#	$(NULL)

test_modetoa_CFLAGS = 			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)


test_modetoa_LDADD = 				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_uglydate_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_uglydate_LDADD = 				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

#removed one combined test, because unity devs suggested we use one program per test
test_libntp_SOURCES =  			\
	modetoa.c			\
	uglydate.c			\
	test-libntp.c			\
	test-libntp.h			\
	run-test-libntp.c		\
	$(NULL)

test_modetoa_SOURCES = 			\
	modetoa.c			\
	run-test-modetoa.c		\
	$(NULL)

test_uglydate_SOURCES = 		\
	uglydate.c			\
	run-test-uglydate.c			\
	$(NULL)

$(srcdir)/run-test-modetoa.c: $(srcdir)/modetoa.c $(std_unity_list)
	$(run_unity) modetoa.c run-test-modetoa.c

$(srcdir)/run-test-uglydate.c: $(srcdir)/uglydate.c $(std_unity_list)
	$(run_unity) uglydate.c run-test-uglydate.c



TESTS =

if !NTP_CROSSCOMPILE
TESTS += $(check_PROGRAMS)
endif

## check-libntp.mf - automake fragment
## slightly adapted for deeper directory

BUILT_SOURCES	+= check-libntp check-libunity
CLEANFILES	+= check-libntp check-libunity

check-libntp: ../../libntp/libntp.a
	@echo stamp > $@

../../libntp/libntp.a:
	cd ../../libntp && $(MAKE) $(AM_MAKEFLAGS) libntp.a

check-libunity: ../../sntp/unity/libunity.a
	@echo stamp > $@

../../sntp/unity/libunity.a:
	cd ../../libunity && $(MAKE) $(AM_MAKEFLAGS) libunity.a

include $(top_srcdir)/depsver.mf
include $(top_srcdir)/includes.mf
