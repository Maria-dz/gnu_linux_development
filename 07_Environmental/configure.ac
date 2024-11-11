#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [1.0], [name])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CC

# Checks for libraries.
CFLAGS="$CFLAGS -I /usr/local/include"
AC_CHECK_LIB([rhash],[rhash_msg],[],[AC_MSG_ERROR([rhash library is not founded])])


AC_ARG_WITH([readlinelib],
            [AS_HELP_STRING([--with-readlinelib],
              [using readline])],
            [],
            [with_readlinelib=no])
          
READLINE_LIB=
AS_IF([test "x$with_readlinelib" != xno],
            [AC_CHECK_LIB([readline], [readline],
              [AC_SUBST([READLINE_LIB], ["-lreadline"])
               AC_DEFINE([USE_READLINE_LIB], [1],
                         [Define if you have readline lib])
              ])])

LDFLAGS="$LDFLAGS -L /usr/local/lib $READLINE_LIB"


# Checks for header files.
AC_CHECK_HEADER([rhash.h], [], [AC_MSG_ERROR([rhash.h not found])])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT