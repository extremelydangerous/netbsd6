$NetBSD$

--- screen.c.orig	2000-03-02 21:43:02.000000000 +0000
+++ screen.c
@@ -157,6 +157,16 @@ static XrmQuark virtualPixmapColorIQ;
  *	Local Functions
  *-------------------------------------------------------------------------*/
 
+static updateScreenWorkspaceColor();
+static updateScreenWindowColor();
+static updateScreenForegroundColor();
+static updateScreenBackgroundColor();
+static updateScreenBorderColor();
+static updateScreenInputFocusColor();
+static updateScreenGlyphFont();
+static void UpdateScreenVirtualPixmapColor(Display *dpy, ScreenInfo *scrInfo);
+
+
 /*
  * makeScreenQuarks -- set up quarks for screen resources
  */
@@ -2422,9 +2432,7 @@ UpdateScreenVirtualFont(dpy,scrInfo)
 /*
  */
 /* ARGSUSED */
-UpdateScreenVirtualGeometry(dpy,scrInfo)
-	Display		*dpy;
-	ScreenInfo	*scrInfo;
+void UpdateScreenVirtualGeometry(Display *dpy, ScreenInfo *scrInfo)
 {
 char	*geom;
 	
@@ -2439,9 +2447,7 @@ char	*geom;
 	VirtualSetGeometry(scrInfo->vdm->client->framewin, geom);
 }
 
-UpdateScreenVirtualMap(dpy,scrInfo)
-	Display		*dpy;
-	ScreenInfo	*scrInfo;
+void UpdateScreenVirtualMap(Display *dpy, ScreenInfo *scrInfo)
 {
 char		*name;
 XSizeHints	*sizeHints;
@@ -2475,9 +2481,7 @@ long		sizeSet;
 	}
 }
 
-UpdateScreenVirtualPixmapColor(dpy,scrInfo)
-	Display		*dpy;
-	ScreenInfo	*scrInfo;
+static void UpdateScreenVirtualPixmapColor(Display *dpy, ScreenInfo *scrInfo)
 {
 	if (!scrInfo->vdm->resources->background)
 	    return;
