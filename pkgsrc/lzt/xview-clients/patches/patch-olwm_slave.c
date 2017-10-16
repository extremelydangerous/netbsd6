$NetBSD$

--- olwm/slave.c.orig	1993-06-29 05:11:57.000000000 +0000
+++ olwm/slave.c
@@ -1,4 +1,3 @@
-#ident	"@(#)slave.c	26.13	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -21,6 +20,9 @@
 #include <X11/Xlib.h>
 #include <signal.h>
 #include <stdio.h>
+#include <stdlib.h>
+
+#include <sys/param.h>
 
 #include "cmdstream.h"
 #include "error.h"
@@ -44,8 +46,7 @@ static SlaveInfo slaveInfo = {
  *	Local Forward Declarations
  * ---------------------------------------------------------------------*/
 
-void	SlaveFailure();
-
+static void	SlaveFailure(void);
 
 /* ----------------------------------------------------------------------
  *	SlaveStart
