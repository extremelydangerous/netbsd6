$NetBSD$

--- plugins/coherence/upnp_coherence/__init__.py.orig	2010-03-25 00:10:11.000000000 +0000
+++ plugins/coherence/upnp_coherence/__init__.py
@@ -12,7 +12,7 @@ import gobject, gtk
 
 import gconf
 
-import louie
+import coherence.extern.louie as louie
 
 from coherence import log
 
