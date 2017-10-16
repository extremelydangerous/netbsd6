$NetBSD$

--- lib-src/libnyquist/nyquist/xlisp/xlisp.h.orig	2016-01-13 14:31:18.000000000 +0000
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h
@@ -151,6 +151,20 @@ extern long ptrtoabs();
 #else
 #define XL_BIG_ENDIAN
 #endif
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
+ #include <sys/endian.h>
+ #if _BYTE_ORDER == _LITTLE_ENDIAN
+  #define XL_LITTLE_ENDIAN
+ #else
+  #define XL_BIG_ENDIAN
+ #endif
+#elif defined(__OpenBSD__) || defined(__Bitrig__)
+ #include <endian.h>
+ #if BYTE_ORDER == _LITTLE_ENDIAN
+  #define XL_LITTLE_ENDIAN
+ #else
+  #define XL_BIG_ENDIAN
+ #endif
 #endif
 
 /* Apple CC */
