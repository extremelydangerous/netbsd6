$NetBSD$

--- backend/dvi/mdvi-lib/tfmfile.c.orig	2010-07-14 07:54:39.000000000 +0000
+++ backend/dvi/mdvi-lib/tfmfile.c
@@ -172,7 +172,8 @@ int	tfm_load_file(const char *filename, 
 	/* We read the entire TFM file into core */
 	if(fstat(fileno(in), &st) < 0)
 		return -1;
-	if(st.st_size == 0)
+	/* according to the spec, TFM files are smaller than 16K */
+	if(st.st_size == 0 || st.st_size >= 16384)
 		goto bad_tfm;
 
 	/* allocate a word-aligned buffer to hold the file */
