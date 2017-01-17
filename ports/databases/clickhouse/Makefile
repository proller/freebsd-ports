# Created by: proler@gmail.com
# $FreeBSD: $

PORTNAME=	clickhouse
PORTVERSION=	1.1.54133
CATEGORIES=	databases

MAINTAINER=	nobody@FreeBSD.org
COMMENT=	ClickHouse is an column-oriented database management system

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libtcmalloc.so:devel/google-perftools \
		libodbc.so:databases/unixODBC \
		libltdl.so:devel/libltdl \
		libicudata.so:devel/icu

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
#GH_TAGNAME=	v${PORTVERSION}-stable # for next version
GH_TAGNAME=	7a526b8

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

USES=		compiler:c++14-lang cmake mysql mysql
USE_GNOME=	glib20
CMAKE_ARGS=	-DUSE_INTERNAL_GPERFTOOLS_LIBRARY=0
USE_GCC=	6+

USE_RC_SUBR=	${PORTNAME}
USERS=		clickhouse
GROUPS=		clickhouse

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/clickhouse|/var/db/clickhouse|' ${WRKSRC}/dbms/src/Server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} ${STAGEDIR}${PREFIX}/include/zconf.h
	@${RM} ${STAGEDIR}${PREFIX}/include/zlib.h
	@${RM} ${STAGEDIR}${PREFIX}/lib/cmake/Poco/PocoConfig.cmake
	@${RM} ${STAGEDIR}${PREFIX}/lib/libz.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libz.so
	@${RM} ${STAGEDIR}${PREFIX}/lib/libz.so.1
	@${RM} ${STAGEDIR}${PREFIX}/lib/libz.so.1.2.8.zlib-ng
	@${RM} ${STAGEDIR}${PREFIX}/share/man/man3/zlib.3
	@${RM} ${STAGEDIR}${PREFIX}/share/pkgconfig/zlib.pc
	@${RMDIR} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/metrika
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake/Poco
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/man/man3
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/man
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/pkgconfig

	${INSTALL_DATA} ${WRKSRC}/dbms/src/Client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${WRKSRC}/dbms/src/Server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${WRKSRC}/dbms/src/Server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

.include <bsd.port.mk>
