# $NetBSD: Makefile,v 1.19 2017/09/06 10:40:36 wiz Exp $
#

DISTNAME=	xscript.tar
PKGNAME=	xscript-19930228
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
MASTER_SITES+=	ftp://ftp.gwdg.de/pub/x11/x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	X Window system script recording and playback

WRKSRC=		${WRKDIR}/test-distrib/src
USE_IMAKE=	YES

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_FLAGS+=	CCOPTIONS=-Wno-error=return-type
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
