$NetBSD$

--- lib/epson-escpr-api-private.h.orig	2017-03-24 01:17:24.000000000 +0000
+++ lib/epson-escpr-api-private.h
@@ -0,0 +1,3 @@
+EPS_ERR_CODE SetupJobAttrib(const EPS_JOB_ATTRIB*);
+EPS_ERR_CODE SendStartJob(EPS_BOOL);
+EPS_ERR_CODE PrintBand(const EPS_UINT8*, EPS_UINT32, EPS_UINT32*);
