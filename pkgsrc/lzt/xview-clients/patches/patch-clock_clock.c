$NetBSD$

--- clock/clock.c.orig	1993-06-29 05:11:39.000000000 +0000
+++ clock/clock.c
@@ -206,6 +206,11 @@ typedef struct clckObject {
 	Menu			menu;
 	} ClockObject, *Clock;
 
+static int min(int a, int b);
+static int armwidth(int r);
+static int seconds_on(Options o);
+static int date_on(Options o);
+
 Server_image	handspr;
 Server_image	spotpr;
 Server_image	dotspr;
