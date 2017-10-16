$NetBSD$

--- olwm/st.c.orig	1993-06-29 05:11:58.000000000 +0000
+++ olwm/st.c
@@ -1,4 +1,3 @@
-#ident	"@(#)st.c	26.8	93/06/28 SMI"
 
 /* This is a general purpose hash table package written by Peter Moore @ UCB. */
 
@@ -6,6 +5,7 @@
 #include "st.h"
 #include "mem.h"
 
+static int rehash(register st_table *table);
 
 #define max(a,b) ((a) > (b) ? (a) : (b))
 #define nil(type) ((type *) 0)
