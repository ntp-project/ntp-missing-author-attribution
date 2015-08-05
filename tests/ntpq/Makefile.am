NULL =
BUILT_SOURCES =
CLEANFILES =

std_unity_list = 						\
	$(top_srcdir)/sntp/unity/auto/generate_test_runner.rb	\
	$(NULL)

run_unity =	cd $(srcdir) && ruby ../../sntp/unity/auto/generate_test_runner.rb

check_PROGRAMS =		\
	test-ntp_scanner	\
	test-ntp_signd		\
	$(NULL)


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

AM_CPPFLAGS += -I$(top_srcdir)/ntpq

AM_CPPFLAGS  = $(NTP_INCS)
#AM_CPPFLAGS += -I$(top_srcdir)/sntp
#AM_CPPFLAGS += -I$(top_srcdir)/ntpd
#AM_CPPFLAGS += -I$(top_srcdir)/tests/libntp
AM_CPPFLAGS += $(GTEST_CPPFLAGS)
AM_CPPFLAGS += $(CPPFLAGS_NTP)
AM_CPPFLAGS += -DUNITY_INCLUDE_CONFIG_H
AM_CPPFLAGS += -I$(top_srcdir)/sntp/unity

AM_LDFLAGS = $(LDFLAGS_NTP)

tests_SOURCES = $(top_srcdir)/sntp/tests_main.cpp	\
		t-ntp_signd.c		\
		$(NULL)

BUILT_SOURCES +=			\
	$(srcdir)/run-rc_cmdlength.c		\
	$(srcdir)/run-t-ntp_signd.c		\
	$(NULL)

noinst_HEADERS =	g_ntpdtest.h		\
			$(srcdir)/../libntp/test-libntp.h	\
			$(srcdir)/../libntp/sockaddrtest.h	\
			$(NULL)

###
test_ntp_signd_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	-Iwhy.h		\
	$(NULL)

test_ntp_signd_LDADD =			\
	$(unity_tests_LDADD)		\
	$(top_builddir)/ntpd/libntpd.a	\
	$(unity_tests_LDADD)		\
	$(top_builddir)/ntpd/ntp_config.o	\
	$(top_builddir)/ntpd/ntp_io.o	\
	$(NULL)

#	$(top_builddir)/ntpd/ntp_signd.o #not needed if you #include the file.c

test_ntp_signd_SOURCES =			\
	t-ntp_signd.c			\
	run-t-ntp_signd.c			\
	$(srcdir)/../libntp/test-libntp.c		\
	$(srcdir)/../../ntpd/ntp_signd.c		\
	$(NULL)

$(srcdir)/run-t-ntp_signd.c: $(srcdir)/t-ntp_signd.c $(std_unity_list)
	$(run_unity) t-ntp_signd.c run-t-ntp_signd.c

###
test_ntp_scanner_CFLAGS =			\
	-I$(top_srcdir)/sntp/unity	\
	$(NULL)

test_ntp_scanner_LDADD =			\
	$(unity_tests_LDADD)		\
	$(top_builddir)/ntpd/ntp_scanner.o		\
	$(NULL)

test_ntp_scanner_SOURCES =			\
	ntp_scanner.c				\
	run-ntp_scanner.c			\
	$(srcdir)/../libntp/test-libntp.c	\
	$(NULL)

$(srcdir)/run-ntp_scanner.c: $(srcdir)/ntp_scanner.c $(std_unity_list)
	$(run_unity) ntp_scanner.c run-ntp_scanner.c



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

$(top_builddir)/ntpd/ntpdsim-ntp_prio_q.o:
	cd ../../ntpd/ && $(MAKE) $(AM_MAKEFLAGS) ntpdsim-ntp_prio_q.o

include $(top_srcdir)/depsver.mf
include $(top_srcdir)/includes.mf
