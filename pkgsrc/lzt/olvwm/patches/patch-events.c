$NetBSD$

--- events.c.orig	1998-01-13 21:00:52.000000000 +0000
+++ events.c
@@ -38,6 +38,8 @@
 
 /* ===== externs ========================================================== */
 
+void CheckOlvwmRC(Display *dpy);
+
 extern void	ReapChildren();
 
 /* ===== globals ========================================================== */
