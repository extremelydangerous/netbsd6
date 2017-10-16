$NetBSD$

--- config-scripts/cups-manpages.m4.orig	2011-05-12 05:21:56.000000000 +0000
+++ config-scripts/cups-manpages.m4
@@ -13,6 +13,8 @@ dnl   which should have been included wi
 dnl   file is missing or damaged, see the license at "http://www.cups.org/".
 dnl
 
+AC_ARG_WITH(manext, [  --with-manext           set man page extension style (bsd,irix,sysv,none)],manext="$withval",manext="")
+ 
 dnl Fix "mandir" variable...
 if test "$mandir" = "\${datarootdir}/man" -a "$prefix" = "/"; then
 	# New GNU "standards" break previous ones, so make sure we use
@@ -50,8 +52,33 @@ AC_SUBST(AMANDIR)
 AC_SUBST(PMANDIR)
 
 dnl Setup manpage extensions...
-case "$uname" in
-	IRIX*)
+if test x$manext = x; then
+	case "$uname" in
+		*BSD* | DragonFly*)
+			# *BSD and Darwin (MacOS X)
+			manext=bsd
+			;;
+		IRIX*)
+			# SGI IRIX
+			manext=irix
+			;;
+		SunOS* | HP-UX*)
+			# Solaris and HP-UX
+			manext=sysv
+			;;
+		Linux* | GNU* | Darwin*)
+			# Linux and GNU Hurd
+			manext=linux
+			;;
+		*)
+			# All others
+			manext=none
+			;;
+	esac
+fi
+
+case "$manext" in
+	irix)
 		# SGI IRIX
 		MAN1EXT=1
 		MAN5EXT=5
@@ -59,7 +86,7 @@ case "$uname" in
 		MAN8EXT=1m
 		MAN8DIR=1
 		;;
-	SunOS* | HP-UX*)
+	sysv)
 		# Solaris and HP-UX
 		MAN1EXT=1
 		MAN5EXT=5
@@ -67,7 +94,7 @@ case "$uname" in
 		MAN8EXT=1m
 		MAN8DIR=1m
 		;;
-	Linux* | GNU* | Darwin*)
+	linux)
 		# Linux, GNU Hurd, and Mac OS X
 		MAN1EXT=1.gz
 		MAN5EXT=5.gz
@@ -75,7 +102,7 @@ case "$uname" in
 		MAN8EXT=8.gz
 		MAN8DIR=8
 		;;
-	*)
+	none|*)
 		# All others
 		MAN1EXT=1
 		MAN5EXT=5
