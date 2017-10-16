$NetBSD: patch-icons.c,v 1.2 2015/12/29 04:04:29 dholland Exp $

Use a more relevant icon to represent NetBSD

--- icons.c.orig	2014-08-26 16:09:22.000000000 -0500
+++ icons.c	2015-01-15 22:06:58.000000000 -0600
@@ -1101,7 +1101,7 @@ jpeg_lrg[] = "\xff\xd8\xff\xe1\x00\x18\x
              "\x6b\x4e\x7a\xe0\x6a\x0a\x51\xa2\x8a\x34\x51\x46\x8a\x28\xd1\x45\x1a\x28\xa3\x45\x14\x68\xa2\x8d"
              "\x14\x51\xa2\x8a\x34\x51\x46\x8a\x28\xd1\x45\x1a\x28\xa3\x45\x14\x68\xa2\x8d\x14\x51\xa2\x8a\xff"
              "\xd9";
-#elif __FreeBSD__
+#elif __FreeBSD__ || __NetBSD__
 /* Small Daemon PNG image */
 unsigned char
 png_sm[] =	"\x89\x50\x4e\x47\x0d\x0a\x1a\x0a\x00\x00\x00\x0d\x49\x48\x44\x52\x00\x00\x00\x29\x00\x00\x00\x30"
