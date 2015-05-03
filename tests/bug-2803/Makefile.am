AUTOMAKE_OPTIONS = foreign 1.9 subdir-objects
NULL =
BUILT_SOURCES =
CLEANFILES =

check_PROGRAMS = bug-2803

# HMS: we may not need some of these:
LDADD =					\
	$(top_builddir)/libntp/libntp.a	\
	$(LDADD_LIBNTP)			\
	$(PTHREAD_LIBS)			\
	$(LDADD_NTP)			\
	$(NULL)

AM_CFLAGS   = $(CFLAGS_NTP)

# HMS: we may not need some of these:
AM_CPPFLAGS  = $(NTP_INCS)
AM_CPPFLAGS += -I$(top_srcdir)/sntp
AM_CPPFLAGS += -I$(top_srcdir)/sntp/unity
AM_CPPFLAGS += -I$(top_srcdir)/ntpd
AM_CPPFLAGS += $(CPPFLAGS_NTP)

AM_LDFLAGS = $(LDFLAGS_NTP)

tests_SOURCES = $(top_srcdir)/sntp/unity/unity.c	\
		bug-2803.c				\
		$(NULL)

# HMS: we may not need some of these:
#noinst_HEADERS =	ntpdtest.h	\
#			$(NULL)

TESTS =

if !NTP_CROSSCOMPILE
TESTS += $(CHECK_PROGRAMS)
endif

## check-libntp.mf - automake fragment
## slightly adapted for deeper directory

BUILT_SOURCES	+= check-libntp
CLEANFILES	+= check-libntp

check-libntp: ../../libntp/libntp.a
	@echo stamp > $@

../../libntp/libntp.a:
	cd ../../libntp && $(MAKE) $(AM_MAKEFLAGS) libntp.a

include $(top_srcdir)/depsver.mf
include $(top_srcdir)/includes.mf
