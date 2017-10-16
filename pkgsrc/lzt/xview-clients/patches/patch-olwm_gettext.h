$NetBSD$

--- olwm/gettext.h.orig	1993-06-29 05:11:46.000000000 +0000
+++ olwm/gettext.h
@@ -1,4 +1,3 @@
-#ident	"@(#)gettext.h	1.7	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -27,7 +26,11 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/param.h>
- 
+
+#ifndef LC_MESSAGES
+#define LC_MESSAGES 0
+#endif
+
 struct domain_binding {
     char    *domain_name;
     char    *binding;
