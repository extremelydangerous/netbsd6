$NetBSD$

--- daemon/getvt.c.orig	2010-06-03 01:06:25.000000000 +0000
+++ daemon/getvt.c
@@ -107,6 +107,8 @@ gdm_get_current_vtnum (Display *display)
 
 #if defined (GDM_USE_SYS_VT)
 #include <sys/vt.h>
+#elif defined (GDM_USE_WSCONS_VT)
+#include <dev/wscons/wsdisplay_usl_io.h>
 #elif defined (GDM_USE_CONSIO_VT)
 #include <sys/consio.h>
 
@@ -139,12 +141,14 @@ gdm_get_vt_device (int vtno)
 #endif
 #elif defined (GDM_USE_CONSIO_VT)
      vtname = g_strdup_printf ("/dev/ttyv%s", __itovty (vtno - 1));
+#elif defined (GDM_USE_WSCONS_VT)
+     vtname = g_strdup_printf ("/dev/ttyE%d", vtno - 1);
 #endif
 
    return vtname;
 }
 
-#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_CONSIO_VT)
+#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_CONSIO_VT) || defined(GDM_USE_WSCONS_VT)
 
 #ifdef __sun
 #define GDMCONSOLEDEVICE "/dev/vt/0"
@@ -175,7 +179,7 @@ open_vt (int vtno)
 	return fd;
 }
 
-#if defined (GDM_USE_SYS_VT)
+#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_WSCONS_VT)
 
 static int 
 get_free_vt_sys (int *vtfd)
@@ -295,7 +299,7 @@ gdm_get_empty_vt_argument (int *fd, int 
 		return NULL;
 	}
 
-#if defined (GDM_USE_SYS_VT)
+#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_WSCONS_VT)
 	*vt = get_free_vt_sys (fd);
 #elif defined (GDM_USE_CONSIO_VT)
 	*vt = get_free_vt_consio (fd);
@@ -337,7 +341,7 @@ gdm_change_vt (int vt)
 int
 gdm_get_current_vt (void)
 {
-#if defined (GDM_USE_SYS_VT)
+#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_WSCONS_VT)
 	struct vt_stat s;
 #elif defined (GDM_USE_CONSIO_VT)
 	int vtno;
@@ -355,7 +359,7 @@ gdm_get_current_vt (void)
 	} while G_UNLIKELY (errno == EINTR);
 	if (fd < 0)
 		return -1;
-#if defined (GDM_USE_SYS_VT)
+#if defined (GDM_USE_SYS_VT) || defined (GDM_USE_WSCONS_VT)
 	ioctl (fd, VT_GETSTATE, &s);
 
 	VE_IGNORE_EINTR (close (fd));
@@ -383,9 +387,9 @@ VE_IGNORE_EINTR (close (fd));
 #endif
 }
 
-#else /* GDM_USE_SYS_VT || GDM_USE_CONSIO_VT - Here this is just
-       * a stub, we do not know how to support this on other
-       * platforms
+#else /* GDM_USE_SYS_VT || GDM_USE_CONSIO_VT || GDM_USE_WSCONS_VT -
+       * Here this is just a stub, we do not know how to support
+       * this on other platforms
        */
 
 char *
