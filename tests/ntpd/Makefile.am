NULL =
BUILT_SOURCES =
CLEANFILES =

run_unity =	cd $(srcdir) && ruby ../../sntp/unity/auto/generate_test_runner.rb

check_PROGRAMS =		\
	test-leapsec		\
	test-rc_cmdlength   \
	test-ntp_signd      \
	$(NULL)

if GTEST_AVAILABLE
check_PROGRAMS += tests
else
EXTRA_PROGRAMS = tests
endif

LDADD =					\
	$(top_builddir)/ntpd/libntpd.a	\
	$(top_builddir)/libntp/libntp.a	\
	$(LDADD_LIBNTP)			\
	$(PTHREAD_LIBS)			\
	$(LDADD_NTP)			\
	$(GTEST_LDFLAGS)		\
	$(GTEST_LIBS)			\
	$(NULL)

unity_tests_LDADD =				\
	$(LDADD)				\
	$(top_builddir)/sntp/unity/libunity.a	\
	$(LIBM)					\
	$(NULL)

AM_CFLAGS   = $(CFLAGS_NTP)
AM_CXXFLAGS = $(GTEST_CXXFLAGS)

AM_CPPFLAGS  = $(NTP_INCS)
AM_CPPFLAGS += -I$(top_srcdir)/sntp
AM_CPPFLAGS += -I$(top_srcdir)/ntpd
AM_CPPFLAGS += -I$(top_srcdir)/tests/libntp
AM_CPPFLAGS += $(GTEST_CPPFLAGS)
AM_CPPFLAGS += $(CPPFLAGS_NTP)
AM_CPPFLAGS += -DUNITY_INCLUDE_CONFIG_H
AM_CPPFLAGS += -I$(top_srcdir)/sntp/unity

AM_LDFLAGS = $(LDFLAGS_NTP)

tests_SOURCES = $(top_srcdir)/sntp/tests_main.cpp	\
		g_ntpdtest.cpp		\
		$(top_srcdir)/ntpd/ntp_leapsec.c	\
		$(top_srcdir)/ntpd/rc_cmdlength.c	\
		$(top_srcdir)/ntpd/ntp_signd.c	\
		g_leapsec.cpp	\
		$(NULL)

BUILT_SOURCES +=			\
	$(srcdir)/run-leapsec.c		\
	$(srcdir)/run-rc_cmdlength.c		\
	$(srcdir)/run-ntp_signd.c		\
	$(NULL)

noinst_HEADERS =	g_ntpdtest.h		\
			$(srcdir)/../libntp/test-libntp.h	\
			$(NULL)

###

test_leapsec_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)
#probably needs -lpthread in LDADD
test_leapsec_LDADD =			\
	$(unity_tests_LDADD)		\
	$(NULL)

test_leapsec_SOURCES =			\
	leapsec.c			\
	run-leapsec.c			\
	$(srcdir)/../libntp/test-libntp.c		\
	$(NULL)

$(srcdir)/run-leapsec.c: $(srcdir)/leapsec.c $(std_unity_list)
	$(run_unity) leapsec.c run-leapsec.c

###
test_rc_cmdlength_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_rc_cmdlength_LDADD =			\
	$(unity_tests_LDADD)		\
	$(NULL)

test_rc_cmdlength_SOURCES =			\
	rc_cmdlength.c			\
	run-rc_cmdlength.c			\
	$(srcdir)/../libntp/test-libntp.c		\
	$(NULL)

$(srcdir)/run-rc_cmdlength.c: $(srcdir)/rc_cmdlength.c $(std_unity_list)
	$(run_unity) rc_cmdlength.c run-rc_cmdlength.c

###
test_ntp_signd_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_ntp_signd_LDADD =			\
	$(unity_tests_LDADD)		\
	$(NULL)

test_ntp_signd_SOURCES =			\
	ntp_signd.c			\
	run-ntp_signd.c			\
	$(srcdir)/../libntp/test-libntp.c		\
	$(NULL)

$(srcdir)/run-ntp_signd.c: $(srcdir)/ntp_signd.c $(std_unity_list)
	$(run_unity) ntp_signd.c run-ntp_signd.c


TESTS =

if !NTP_CROSSCOMPILE
TESTS += $(check_PROGRAMS)
endif

## check-libntp.mf - automake fragment
## slightly adapted for deeper directory

BUILT_SOURCES	+= check-libntpd check-libntp check-libunity 
CLEANFILES	+= check-libntpd check-libntp check-libunity 

check-libntpd: ../../ntpd/libntpd.a
	@echo stamp > $@

../../ntpd/libntpd.a:
	cd ../../ntpd && $(MAKE) $(AM_MAKEFLAGS) libntpd.a


check-libntp: ../../libntp/libntp.a
	@echo stamp > $@

../../libntp/libntp.a:
	cd ../../libntp && $(MAKE) $(AM_MAKEFLAGS) libntp.a


check-libunity: ../../sntp/unity/libunity.a
	@echo stamp > $@

../../sntp/unity/libunity.a:
	cd ../../sntp/unity && $(MAKE) $(AM_MAKEFLAGS) libunity.a

include $(top_srcdir)/depsver.mf
include $(top_srcdir)/includes.mf
