$NetBSD: patch-libcc1_connection.cc,v 1.1 2017/07/03 17:32:14 ryoon Exp $

--- libcc1/connection.cc.orig	2014-11-13 10:22:22.000000000 +0000
+++ libcc1/connection.cc
@@ -23,6 +23,7 @@ along with GCC; see the file COPYING3.  
 #include <sys/types.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/select.h>
 #include "marshall.hh"
 #include "connection.hh"
 #include "rpc.hh"
