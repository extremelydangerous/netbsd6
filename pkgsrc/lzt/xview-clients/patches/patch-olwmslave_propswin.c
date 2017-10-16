$NetBSD$

--- olwmslave/propswin.c.orig	1993-06-29 05:12:13.000000000 +0000
+++ olwmslave/propswin.c
@@ -38,9 +38,9 @@ static WindowProps	*winPropsList = 0; 	/
  *      Local Forward Declarations
  * ----------------------------------------------------------------------*/
 int		ShowWindowProps();
-void		InitWindowProps();
-Bool		CreateWindowProps();
-Notify_value	DestroyWindowProps();
+static void		InitWindowProps();
+static Bool		CreateWindowProps();
+static Notify_value	DestroyWindowProps();
 void		ApplyProps();
 void		ResetProps();
 
