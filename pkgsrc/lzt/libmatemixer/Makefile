# $NetBSD: Makefile,v 1.2 2016/08/03 10:22:30 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${MATE_VERSION}
CATEGORIES=	audio

COMMENT=	MATE audio mixer

CONFIGURE_ARGS+=	--disable-null \
			--enable-oss \
			--disable-alsa \
			--enable-pulseaudio \

.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"


cvs:
	cvs up
	cvs commit
