$NetBSD$

--- directory.cpp.orig	2000-01-11 00:44:44.000000000 +0000
+++ directory.cpp
@@ -1,10 +1,13 @@
 #include <cctype>
+#include <cstring>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <unistd.h>
 
 #include "directory.h"
 
+using namespace std;
+
 directory::~directory (void)
 {
 }
@@ -48,8 +51,8 @@ ttfdirectory::select (const char *name) 
     /* we make the decision by the extension of the file name */
     return (((len = strlen (name)) > 4) &&
 	    (name[len - 4] == '.') &&
-	    (std::toupper(name[len - 3]) == 'T') &&
-	    (std::toupper(name[len - 2]) == 'T') &&
-	    ((std::toupper(name[len - 1]) == 'F') ||
-	     (std::toupper(name[len - 1]) == 'C')));
+	    (toupper(name[len - 3]) == 'T') &&
+	    (toupper(name[len - 2]) == 'T') &&
+	    ((toupper(name[len - 1]) == 'F') ||
+	     (toupper(name[len - 1]) == 'C')));
 }
