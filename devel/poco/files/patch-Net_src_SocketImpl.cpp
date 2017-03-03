--- Net/src/SocketImpl.cpp.orig	2017-03-03 18:27:35.000000000 +0000
+++ Net/src/SocketImpl.cpp	2017-03-03 18:27:48.465239000 +0000
@@ -473,7 +473,7 @@
 		}
 	}
 	while (rc < 0 && lastError() == POCO_EINTR);
-	if (rc < 0) error(errorCode);
+	if (rc < 0) error();
 	return rc > 0; 
 
 #else
