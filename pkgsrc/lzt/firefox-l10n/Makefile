# $NetBSD: Makefile,v 1.97 2016/12/18 01:32:18 ryoon Exp $
#

FIREFOX_VER=	50.1.0
PKGNAME=	firefox-l10n-${FIREFOX_VER:S/esr//}
DISTNAME=	# empty
CATEGORIES=	www
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Language packs for www/firefox (version ${PKGVERSION_NOREV:C/\..*//})

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

FIREFOX_LOCALES=ach af an ar as ast az be bg bn-BD bn-IN br bs ca cs	\
		cy da de dsb el en-GB en-ZA eo es-AR es-CL 	\
		es-ES es-MX et eu fa ff fi fr fy-NL ga-IE gd gl gn gu-IN \
		he hi-IN hr hsb hu hy-AM id is it ja kk km kn ko lij	\
		lt lv mai mk ml mr ms nb-NO nl nn-NO or pa-IN pl pt-BR	\
		pt-PT rm ro ru si sk sl son sq sr sv-SE ta te th tr	\
		uk uz vi xh zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/firefox/browser/extensions
XPI_FILES=		${FIREFOX_LOCALES:=.xpi}

.include "../firefox/buildlink3.mk"
.include "../firefox/xpi.mk"
.include "../../mk/bsd.pkg.mk"
