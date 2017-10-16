$NetBSD$

--- backend/dvi/mdvi-lib/pk.c.orig	2010-07-14 07:54:39.000000000 +0000
+++ backend/dvi/mdvi-lib/pk.c
@@ -469,6 +469,15 @@ static int pk_load_font(DviParams *unuse
 			}
 			if(feof(p))
 				break;
+
+			/* Although the PK format support bigger char codes,
+                         * XeTeX and other extended TeX engines support charcodes up to
+                         * 65536, while normal TeX engine supports only charcode up to 255.*/
+			if (cc < 0 || cc > 65536) {
+				mdvi_error (_("%s: unexpected charcode (%d)\n"),
+					    font->fontname,cc);
+				goto error;
+			} 
 			if(cc < loc)
 				loc = cc;
 			if(cc > hic)
@@ -512,7 +521,7 @@ static int pk_load_font(DviParams *unuse
 	}
 
 	/* resize font char data */
-	if(loc > 0 || hic < maxch-1) {
+	if(loc > 0 && hic < maxch-1) {
 		memmove(font->chars, font->chars + loc, 
 			(hic - loc + 1) * sizeof(DviFontChar));
 		font->chars = xresize(font->chars,
