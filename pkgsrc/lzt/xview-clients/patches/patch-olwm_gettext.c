$NetBSD$

--- olwm/gettext.c.orig	1993-06-29 05:11:46.000000000 +0000
+++ olwm/gettext.c
@@ -1,4 +1,3 @@
-#ident	"@(#)gettext.c	1.10	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -15,12 +14,14 @@
 #define bzero(a,b) memset(a,0,b)
 #endif
 
-char *malloc(), *strdup();
-char * dgettext();
+char * dgettext(char *, char *);
 char *_gettext();
+#include <stdlib.h>
+#include <stdio.h>
+#include <sys/types.h>
+#include <sys/mman.h>
+
 char *in_path();
-char *fgets(), *getenv();
-caddr_t mmap(), calloc();
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
