$NetBSD$

--- src/formats.c.orig	2014-10-27 02:55:50.000000000 +0000
+++ src/formats.c
@@ -411,18 +411,23 @@ static void UNUSED rewind_pipe(FILE * fp
 /* _FSTDIO is for Torek stdio (i.e. most BSD-derived libc's)
  * In theory, we no longer need to check _NEWLIB_VERSION or __APPLE__ */
 #if defined _FSTDIO || defined _NEWLIB_VERSION || defined __APPLE__
+#  ifdef __DragonFly__
+  struct __FILE_public *fpp = (struct __FILE_public *)fp;
+  fpp->_p -= AUTO_DETECT_SIZE;
+  fpp->_r += AUTO_DETECT_SIZE;
+#  else
   fp->_p -= PIPE_AUTO_DETECT_SIZE;
   fp->_r += PIPE_AUTO_DETECT_SIZE;
+#  endif
 #elif defined __GLIBC__
   fp->_IO_read_ptr = fp->_IO_read_base;
 #elif defined _MSC_VER || defined _WIN32 || defined _WIN64 || \
-      defined _ISO_STDIO_ISO_H || defined __sgi
+      (defined _ISO_STDIO_ISO_H && !(defined(__sun) && defined(_LP64))) || defined __sgi
   fp->_ptr = fp->_base;
 #else
   /* To fix this #error, either simply remove the #error line and live without
    * file-type detection with pipes, or add support for your compiler in the
    * lines above.  Test with cat monkey.wav | ./sox --info - */
-  #error FIX NEEDED HERE
   #define NO_REWIND_PIPE
   (void)fp;
 #endif
