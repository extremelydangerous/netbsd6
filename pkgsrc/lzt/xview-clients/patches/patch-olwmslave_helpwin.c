$NetBSD$

--- olwmslave/helpwin.c.orig	1993-06-29 05:12:11.000000000 +0000
+++ olwmslave/helpwin.c
@@ -6,7 +6,6 @@
 /* ----------------------------------------------------------------------
  *	helpwin.c
  * ---------------------------------------------------------------------*/
-#ident	"@(#)helpwin.c	1.13 93/06/28 helpwin.c SMI"
 
 #include <stdio.h>
 #include <xview/xview.h>
@@ -128,14 +127,15 @@ char		*help_get_text();
  *	Local Forward Functions
  * ---------------------------------------------------------------------*/
 int		ShowHelpWindow();
-void		InitHelpWindow();
-Bool		CreateHelpWindow();
-Notify_value	DestroyHelpWindow();
-void		ResetHelpWindow();
-Bool		TextHelpWindow();
-Bool		ImageHelpWindow();
-void		MoreHelp();
-void		ErrorNotice();
+static void		InitHelpWindow();
+static Bool		CreateHelpWindow();
+static Notify_value	DestroyHelpWindow();
+static void		ResetHelpWindow();
+static Bool		TextHelpWindow();
+static Bool		ImageHelpWindow();
+static void		MoreHelp();
+static void		ErrorNotice();
+static int	ConstrainMousePos();
 
 /* ----------------------------------------------------------------------
  *	ShowHelpWindow
