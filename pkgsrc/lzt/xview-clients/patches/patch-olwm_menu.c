$NetBSD$

--- olwm/menu.c.orig	1993-06-29 05:11:50.000000000 +0000
+++ olwm/menu.c
@@ -1,4 +1,3 @@
-#ident	"@(#)menu.c	26.76	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -52,6 +51,8 @@ static int  lastX, lastY, minX;
 static WinGeneric *prevColorFocusWindow = NULL;
 static MenuTrackMode menuTrackMode;
 
+static Bool isEnabled();
+
 /*
  * Table of currently active menus.
  * REMIND: perhaps this should be dynamically allocated.
