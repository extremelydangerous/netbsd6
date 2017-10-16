$NetBSD$

--- olwm.c.orig	2000-03-02 21:43:52.000000000 +0000
+++ olwm.c
@@ -67,6 +67,7 @@ GlobalResourceVariables GRV;		/* variabl
 XrmDatabase	OlwmDB;			/* the main resource database */
 Display		*DefDpy;		/* the display connection */
 
+void InitOlvwmRC(Display *ldpy, char *path);
 
 #ifdef DEBUG
 
@@ -675,12 +676,11 @@ ReapChildren()
 {
 #ifdef SYSV
         pid_t pid;
-        int status;
 #else
 	int oldmask;
 	int pid;
-	union wait status;
 #endif
+	int status;
 
 	if (!deadChildren)
 		return;
