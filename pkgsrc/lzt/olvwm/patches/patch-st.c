$NetBSD$

--- st.c.orig	2000-03-02 21:40:47.000000000 +0000
+++ st.c
@@ -44,6 +44,8 @@
 	(table->hash == ST_NUMHASH) ? ((int) (key) % table->num_bins) :\
 	(*table->hash)((key), table->num_bins))*/
 
+static rehash();
+
 st_table *st_init_table_with_params(compare, hash, size, density, grow_factor,
 				    reorder_flag)
 int (*compare)();
@@ -320,10 +322,7 @@ char **value;
     return 0;
 }
 
-st_foreach(table, func, arg)
-st_table *table;
-enum st_retval (*func)();
-char *arg;
+void st_foreach(st_table *table, enum st_retval (*func)(), char *arg)
 {
     st_table_entry *ptr, *last, *tmp;
     enum st_retval retval;
