$NetBSD$

--- backend/dvi/mdvi-lib/vf.c.orig	2010-07-14 07:54:39.000000000 +0000
+++ backend/dvi/mdvi-lib/vf.c
@@ -165,6 +165,12 @@ static int vf_load_font(DviParams *param
 			cc = fuget1(p);
 			tfm = fuget3(p);
 		}
+		if (cc < 0 || cc > 65536) {
+			/* TeX engines do not support char codes bigger than 65535 */
+			mdvi_error(_("(vf) %s: unexpected character %d\n"),
+				   font->fontname, cc);
+			goto error;
+		}
 		if(loc < 0 || cc < loc)
 			loc = cc;
 		if(hic < 0 || cc > hic)
