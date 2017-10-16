$NetBSD: patch-src_hashmap.c,v 1.1 2012/12/13 09:01:26 wiz Exp $

Fix CVE-2012-3505 using Debian patch.

--- src/hashmap.c.orig	2010-01-25 18:24:01.000000000 +0000
+++ src/hashmap.c
@@ -25,6 +25,8 @@
  * don't try to free the data, or realloc the memory. :)
  */
 
+#include <stdlib.h>
+
 #include "main.h"
 
 #include "hashmap.h"
@@ -50,6 +52,7 @@ struct hashbucket_s {
 };
 
 struct hashmap_s {
+        uint32_t seed;
         unsigned int size;
         hashmap_iter end_iterator;
 
@@ -65,7 +68,7 @@ struct hashmap_s {
  *
  * If any of the arguments are invalid a negative number is returned.
  */
-static int hashfunc (const char *key, unsigned int size)
+static int hashfunc (const char *key, unsigned int size, uint32_t seed)
 {
         uint32_t hash;
 
@@ -74,7 +77,7 @@ static int hashfunc (const char *key, un
         if (size == 0)
                 return -ERANGE;
 
-        for (hash = tolower (*key++); *key != '\0'; key++) {
+        for (hash = seed; *key != '\0'; key++) {
                 uint32_t bit = (hash & 1) ? (1 << (sizeof (uint32_t) - 1)) : 0;
 
                 hash >>= 1;
@@ -104,6 +107,7 @@ hashmap_t hashmap_create (unsigned int n
         if (!ptr)
                 return NULL;
 
+	ptr->seed = (uint32_t)rand();
         ptr->size = nbuckets;
         ptr->buckets = (struct hashbucket_s *) safecalloc (nbuckets,
                                                            sizeof (struct
@@ -201,7 +205,7 @@ hashmap_insert (hashmap_t map, const cha
         if (!data || len < 1)
                 return -ERANGE;
 
-        hash = hashfunc (key, map->size);
+        hash = hashfunc (key, map->size, map->seed);
         if (hash < 0)
                 return hash;
 
@@ -382,7 +386,7 @@ ssize_t hashmap_search (hashmap_t map, c
         if (map == NULL || key == NULL)
                 return -EINVAL;
 
-        hash = hashfunc (key, map->size);
+        hash = hashfunc (key, map->size, map->seed);
         if (hash < 0)
                 return hash;
 
@@ -416,7 +420,7 @@ ssize_t hashmap_entry_by_key (hashmap_t 
         if (!map || !key || !data)
                 return -EINVAL;
 
-        hash = hashfunc (key, map->size);
+        hash = hashfunc (key, map->size, map->seed);
         if (hash < 0)
                 return hash;
 
@@ -451,7 +455,7 @@ ssize_t hashmap_remove (hashmap_t map, c
         if (map == NULL || key == NULL)
                 return -EINVAL;
 
-        hash = hashfunc (key, map->size);
+        hash = hashfunc (key, map->size, map->seed);
         if (hash < 0)
                 return hash;
 
