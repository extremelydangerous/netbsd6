$NetBSD$

--- olwmslave/mem.c.orig	1993-06-29 05:12:12.000000000 +0000
+++ olwmslave/mem.c
@@ -16,7 +16,12 @@ static	char	sccsid[] = "@(#) mem.c 26.1 
  *
  */
 
+#include <sys/param.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <memory.h>
 #include <stdio.h>
 #include <sys/types.h>
