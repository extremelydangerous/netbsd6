# $NetBSD: Makefile,v 1.26 2016/07/09 06:38:34 wiz Exp $

DISTNAME=		superlu_3.0
PKGNAME=		superlu-3.0.1
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		http://crd.lbl.gov/~xiaoye/SuperLU/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://crd.lbl.gov/~xiaoye/SuperLU/
COMMENT=		ANSI C routine library for the solution of sparse linear systems

# /usr/bin/ar: ../libsuperlu.a: Error reading dlamch.o: File truncated
MAKE_JOBS_SAFE=		no

DEPENDS+=		blas-[0-9]*:../../math/blas

DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}/SuperLU_3.0
BUILD_TARGET=		superlulib
TEST_DIRS=		TESTING/MATGEN TESTING
TEST_TARGET=		all
INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${DESTDIR}${PREFIX}/include/superlu
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/superlu
	${INSTALL_DATA} ${WRKSRC}/INSTALL/ug.ps ${DESTDIR}${PREFIX}/share/doc/superlu

.include "../../mk/bsd.pkg.mk"
