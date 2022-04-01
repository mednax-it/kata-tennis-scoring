## Process this file with automake to produce Makefile.in

TESTS = check_tennis_scoring
check_PROGRAMS = check_tennis_scoring
check_tennis_scoring_SOURCES = check_tennis_scoring.c $(top_builddir)/src/tennis_scoring.h
check_tennis_scoring_CFLAGS = @CHECK_CFLAGS@
check_tennis_scoring_LDADD = $(top_builddir)/src/libtennis_scoring.la @CHECK_LIBS@
