$NetBSD$

--- config-scripts/cups-3264.m4.orig	2011-05-12 05:21:56.000000000 +0000
+++ config-scripts/cups-3264.m4
@@ -95,7 +95,7 @@ case "$uname" in
 			LIB32CUPS="32bit/libcups.so.2"
 			LIB32CUPSIMAGE="32bit/libcupsimage.so.2"
 			LIB32DIR="$exec_prefix/lib"
-			if test -d /usr/lib32; then
+			if test -d /usr/lib32 && false; then
 				LIB32DIR="${LIB32DIR}32"
 			fi
 			UNINSTALL32="uninstall32bit"
@@ -107,7 +107,7 @@ case "$uname" in
 			LIB64CUPS="64bit/libcups.so.2"
 			LIB64CUPSIMAGE="64bit/libcupsimage.so.2"
 			LIB64DIR="$exec_prefix/lib"
-			if test -d /usr/lib64; then
+			if test -d /usr/lib64 && false; then
 				LIB64DIR="${LIB64DIR}64"
 			fi
 			UNINSTALL64="uninstall64bit"
