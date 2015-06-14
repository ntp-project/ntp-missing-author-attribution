NULL =
BUILT_SOURCES =
CLEANFILES =

run_unity =	cd $(srcdir) && ruby ../../sntp/unity/auto/generate_test_runner.rb

#removed test-libntp
check_PROGRAMS =		\
	test-modetoa		\
	test-uglydate		\
	test-ymd2yd		\
	test-statestr		\
	test-numtoa		\
	test-numtohost		\
	test-hextoint		\
	test-atoint		\
	test-atouint		\
	test-authkeys		\
	test-a_md5encrypt	\
	test-lfpfunc		\
	test-vi64ops		\
	test-refnumtoa		\
	test-calyearstart	\
	test-clocktime		\
	test-caljulian		\
	$(NULL)

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
	$(LIBM)				\
	$(NULL)

tests_LDADD =				\
	$(LDADD)			\
	$(GTEST_LDFLAGS)		\
	$(GTEST_LIBS)			\
	$(NULL)

unity_tests_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

AM_CFLAGS   = $(CFLAGS_NTP)
AM_CXXFLAGS = $(GTEST_CXXFLAGS)

AM_CPPFLAGS  = $(NTP_INCS)
AM_CPPFLAGS += -I$(top_srcdir)/sntp
AM_CPPFLAGS += $(GTEST_CPPFLAGS)
AM_CPPFLAGS += $(CPPFLAGS_NTP)

AM_LDFLAGS = $(LDFLAGS_NTP)

tests_SOURCES =					\
		$(top_srcdir)/sntp/tests_main.cpp	\
		libntptest.cpp		\
		g_a_md5encrypt.cpp	\
		g_atoint.cpp		\
		g_atouint.cpp		\
		g_authkeys.cpp		\
		buftvtots.cpp		\
		calendar.cpp		\
		g_caljulian.cpp		\
		caltontp.cpp		\
		g_calyearstart.cpp	\
		g_clocktime.cpp		\
		decodenetnum.cpp	\
		g_hextoint.cpp		\
		hextolfp.cpp		\
		humandate.cpp		\
		g_lfpfunc.cpp		\
		lfptostr.cpp		\
		g_modetoa.cpp		\
		msyslog.cpp		\
		netof.cpp		\
		g_numtoa.cpp		\
		g_numtohost.cpp		\
		octtoint.cpp		\
		prettydate.cpp		\
		recvbuff.cpp		\
		g_refnumtoa.cpp		\
		sfptostr.cpp		\
		socktoa.cpp		\
		ssl_init.cpp		\
		g_statestr.cpp		\
		strtolfp.cpp		\
		timespecops.cpp		\
		timestructs.cpp		\
		timevalops.cpp		\
		tstotv.cpp		\
		tvtots.cpp		\
		g_uglydate.cpp		\
		g_vi64ops.cpp		\
		g_ymd2yd.cpp		\
		$(NULL)

noinst_HEADERS =	\
	lfptest.h	\
	libntptest.h	\
	sockaddrtest.h	\
	timestructs.h	\
	$(NULL)

#$(srcdir)/run-test-libntp.c: $(srcdir)/test-libntp.c $(std_unity_list)
#	$(run_unity) test-libntp.c run-test-libntp.c

#test_libntp_CFLAGS =			\
#	-I$(top_srcdir)/sntp/unity	\
#	$(NULL)

#test_libntp_LDADD =				\
#	$(LDADD)				\
#	$(top_builddir)/sntp/unity/libunity.a	\
#	$(NULL)

test_modetoa_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_modetoa_LDADD = 				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_uglydate_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_uglydate_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_ymd2yd_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_ymd2yd_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_statestr_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_statestr_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_numtoa_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_numtoa_LDADD =				\
	$(unity_tests_LDADD)			\
	$(NULL)

test_numtohost_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_numtohost_LDADD =				\
	$(unity_tests_LDADD)			\
	$(NULL)

test_hextoint_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_hextoint_LDADD =				\
	$(unity_tests_LDADD)
	$(NULL)

test_atoint_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_atoint_LDADD =				\
	$(unity_tests_LDADD)
	$(NULL)

test_a_md5encrypt_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_a_md5encrypt_LDADD =			\
	$(unity_tests_LDADD)			\
	$(NULL)

test_atouint_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_atouint_LDADD =				\
	$(unity_tests_LDADD)
	$(NULL)

test_authkeys_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_authkeys_LDADD =				\
	$(unity_tests_LDADD)			\
	$(NULL)

test_lfpfunc_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	-DUNITY_INCLUDE_DOUBLE			\
	$(NULL)

test_lfpfunc_LDADD =				\
	$(unity_tests_LDADD)			\
	$(NULL)

test_vi64ops_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_vi64ops_LDADD =				\
	$(unity_tests_LDADD)			\
	$(NULL)

test_refnumtoa_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_refnumtoa_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_calyearstart_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_calyearstart_LDADD =			\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_clocktime_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_clocktime_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_caljulian_CFLAGS =				\
	-I$(top_srcdir)/sntp/unity		\
	$(NULL)

test_caljulian_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(NULL)

test_modetoa_SOURCES =			\
	modetoa.c			\
	run-test-modetoa.c		\
	$(NULL)

test_uglydate_SOURCES =			\
	uglydate.c			\
	run-test-uglydate.c		\
	$(NULL)

test_ymd2yd_SOURCES =			\
	ymd2yd.c			\
	run-test-ymd2yd.c		\
	$(NULL)

test_statestr_SOURCES =			\
	statestr.c			\
	run-test-statestr.c		\
	$(NULL)

test_numtoa_SOURCES =			\
	numtoa.c			\
	run-test-numtoa.c		\
	$(NULL)

test_numtohost_SOURCES =		\
	numtohost.c			\
	run-test-numtohost.c		\
	$(NULL)

test_hextoint_SOURCES =			\
	hextoint.c			\
	run-test-hextoint.c		\
	$(NULL)

test_atoint_SOURCES =			\
	atoint.c			\
	run-test-atoint.c		\
	$(NULL)

test_a_md5encrypt_SOURCES =		\
	a_md5encrypt.c			\
	run-test-a_md5encrypt.c		\
	$(NULL)

test_atouint_SOURCES =			\
	atouint.c			\
	run-test-atouint.c		\
	$(NULL)

test_authkeys_SOURCES =			\
	authkeys.c			\
	run-test-authkeys.c		\
	$(NULL)

test_lfpfunc_SOURCES =			\
	lfpfunc.c			\
	run-test-lfpfunc.c		\
	$(NULL)

test_vi64ops_SOURCES =			\
	vi64ops.c			\
	run-test-vi64ops.c		\
	$(NULL)

test_refnumtoa_SOURCES =		\
	refnumtoa.c			\
	run-test-refnumtoa.c		\
	$(NULL)

test_calyearstart_SOURCES =		\
	calyearstart.c			\
	run-test-calyearstart.c		\
	test-libntp.c			\
	$(NULL)

test_clocktime_SOURCES =		\
	clocktime.c			\
	run-test-clocktime.c		\
	test-libntp.c			\
	$(NULL)

test_caljulian_SOURCES =		\
	caljulian.c			\
	run-test-caljulian.c		\
	test-libntp.c			\
	$(NULL)

BUILT_SOURCES +=				\
	$(srcdir)/run-test-a_md5encrypt.c	\
	$(srcdir)/run-test-atoint.c		\
	$(srcdir)/run-test-atouint.c		\
	$(srcdir)/run-test-authkeys.c		\
	$(srcdir)/run-test-caljulian.c		\
	$(srcdir)/run-test-calyearstart.c	\
	$(srcdir)/run-test-clocktime.c		\
	$(srcdir)/run-test-hextoint.c		\
	$(srcdir)/run-test-lfpfunc.c		\
	$(srcdir)/run-test-modetoa.c		\
	$(srcdir)/run-test-numtoa.c		\
	$(srcdir)/run-test-numtohost.c		\
	$(srcdir)/run-test-refnumtoa.c		\
	$(srcdir)/run-test-statestr.c		\
	$(srcdir)/run-test-uglydate.c		\
	$(srcdir)/run-test-vi64ops.c		\
	$(srcdir)/run-test-ymd2yd.c		\
	$(NULL)

$(srcdir)/run-test-modetoa.c: $(srcdir)/modetoa.c $(std_unity_list)
	$(run_unity) modetoa.c run-test-modetoa.c

$(srcdir)/run-test-uglydate.c: $(srcdir)/uglydate.c $(std_unity_list)
	$(run_unity) uglydate.c run-test-uglydate.c

$(srcdir)/run-test-ymd2yd.c: $(srcdir)/ymd2yd.c $(std_unity_list)
	$(run_unity) ymd2yd.c run-test-ymd2yd.c

$(srcdir)/run-test-statestr.c: $(srcdir)/statestr.c $(std_unity_list)
	$(run_unity) statestr.c run-test-statestr.c

$(srcdir)/run-test-numtoa.c: $(srcdir)/numtoa.c $(std_unity_list)
	$(run_unity) numtoa.c run-test-numtoa.c

$(srcdir)/run-test-numtohost.c: $(srcdir)/numtohost.c $(std_unity_list)
	$(run_unity) numtohost.c run-test-numtohost.c

$(srcdir)/run-test-hextoint.c: $(srcdir)/hextoint.c $(std_unity_list)
	$(run_unity) hextoint.c run-test-hextoint.c

$(srcdir)/run-test-atoint.c: $(srcdir)/atoint.c $(std_unity_list)
	$(run_unity) atoint.c run-test-atoint.c

$(srcdir)/run-test-a_md5encrypt.c: $(srcdir)/a_md5encrypt.c $(std_unity_list)
	$(run_unity) a_md5encrypt.c run-test-a_md5encrypt.c

$(srcdir)/run-test-atouint.c: $(srcdir)/atouint.c $(std_unity_list)
	$(run_unity) atouint.c run-test-atouint.c

$(srcdir)/run-test-authkeys.c: $(srcdir)/authkeys.c $(std_unity_list)
	$(run_unity) authkeys.c run-test-authkeys.c

$(srcdir)/run-test-lfpfunc.c: $(srcdir)/lfpfunc.c $(std_unity_list)
	$(run_unity) lfpfunc.c run-test-lfpfunc.c

$(srcdir)/run-test-vi64ops.c: $(srcdir)/vi64ops.c $(std_unity_list)
	$(run_unity) vi64ops.c run-test-vi64ops.c

$(srcdir)/run-test-refnumtoa.c: $(srcdir)/refnumtoa.c $(std_unity_list)
	$(run_unity) refnumtoa.c run-test-refnumtoa.c

$(srcdir)/run-test-calyearstart.c: $(srcdir)/calyearstart.c $(std_unity_list)
	$(run_unity) calyearstart.c run-test-calyearstart.c

$(srcdir)/run-test-clocktime.c: $(srcdir)/clocktime.c $(std_unity_list)
	$(run_unity) clocktime.c run-test-clocktime.c

$(srcdir)/run-test-caljulian.c: $(srcdir)/caljulian.c $(std_unity_list)
	$(run_unity) caljulian.c run-test-caljulian.c

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
