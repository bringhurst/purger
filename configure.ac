################################################################################
# Copyright 2008-2009 Los Alamos National Security, LLC. All Rights Reserved.  #
#                                                                              #
# Redistribution and use in source and binary forms, with or without           #
# modification, are permitted provided that the following conditions are met:  #
#                                                                              #
#                                                                              #
#   o Redistributions of source code must retain the above copyright notice,   #
#     this list of conditions and the following disclaimer.                    #
#   o Redistributions in binary form must reproduce the above copyright        #
#     notice, this list of conditions and the following disclaimer in the      #
#     documentation and/or other materials provided with the distribution.     #
#   o Neither the name of the copyright holders nor the names of its           #
#     contributors may be used to endorse or promote products derived from     #
#     this software without specific prior written permission.                 #
#                                                                              #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  #
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   #
# POSSIBILITY OF SUCH DAMAGE.                                                  #
################################################################################

#AC_PREREQ([2.65])
AC_INIT([lanl-purger], [1.0.0], [jlafon@lanl.gov])
AC_COPYRIGHT([
        [Copyright 2008-2010 Los Alamos National Security, LLC. All Rights Reserved.]
        ])

# Put all build stuff in config
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([config])
    
AM_INIT_AUTOMAKE([foreign])

define([AC_LIBTOOL_LANG_CXX_CONFIG], [:])dnl
define([AC_LIBTOOL_LANG_F77_CONFIG], [:])dnl
# Minimize output    
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])
AC_GNU_SOURCE

AC_PROG_CC
AC_PROG_CC_C_O
AC_SUBST(version_info)
AM_PROG_CC_C_O
# Not necessary but doesn't hurt anything
AC_CONFIG_HEADERS([config.h])
#AC_USE_SYSTEM_EXTENSIONS
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_CHECK_HEADERS([netdb.h netinet/in.h stdlib.h string.h sys/socket.h sys/time.h unistd.h])
AC_CHECK_PROG(PGCONFIG,pg_config,pg_config,false)
if test "x$PGCONFIG" = "xfalse"; then
	AC_MSG_ERROR([pg_config is required.])
fi
AC_SEARCH_LIBS([socket],[socket], , LIBS+=-L`pg_config --libdir`)
AC_SEARCH_LIBS([PQexec],[pq], , LIBS+=-L`pg_config --libdir`)
AC_OUTPUT([
        Makefile
        lib/config/Makefile
        lib/ldap/Makefile
        lib/log/Makefile
        lib/mail/Makefile
        src/prm/Makefile
        lib/utils/Makefile
        src/Makefile
        lib/Makefile
        test/Makefile
        test/email/Makefile
        test/ldap/Makefile
        test/log/Makefile
        test/insert/Makefile
        src/purger/Makefile
        src/treewalk/Makefile
        src/util/Makefile
   	lanl-purger.spec
	])
AC_OUTPUT
