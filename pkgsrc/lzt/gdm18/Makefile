# $NetBSD: Makefile,v 1.133 2007/10/11 09:46:51 hauke Exp $
#

DISTNAME=	gdm-2.18.4
PKGREVISION=	5
CATEGORIES=	lzt x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

BUILDLINK_API_DEPENDS.libart+=	libart>=2.3.11

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

USE_LANGUAGES+=		c c++

.if !empty(MACHINE_ARCH:Marm*)
USE_LANGUAGES+=		fortran
.endif

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-dmconfdir=${PKG_SYSCONFDIR:Q}/dm
CONFIGURE_ARGS+=	--with-sysconfsubdir=
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	GDM_CUSTOM_CONF=${EGDIR:Q}/custom.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostLogin
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/dm
OWN_DIRS+=		${PKG_SYSCONFDIR}/modules
OWN_DIRS+=		${VARBASE}/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

INSTALLATION_DIRS+=	share/examples/gdm

PKG_SYSCONFSUBDIR=	gdm

EGDIR=			${PREFIX}/share/examples/gdm

CONF_FILES_PERMS+=	${EGDIR}/xprofile.mate  /etc/xprofile \
			${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES=
.for f in custom.conf locale.alias dconf.default \
	modules/AccessDwellMouseEvents modules/AccessKeyMouseEvents \
	modules/factory-AccessDwellMouseEvents \
	modules/factory-AccessKeyMouseEvents
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.for f in Init/Default PostLogin/Default.sample PostSession/Default \
	PreSession/Default XKeepsCrashing Xsession
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	Configuring GDM settings.
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	config/default.desktop.in
#SUBST_FILES.desktop+=	config/gnome.desktop.in
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|^User=gdm$$|User=${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|^Group=gdm$$|Group=${GDMGRP}|g'
.if ${OPSYS} == "NetBSD"
SUBST_SED.desktop+=	-e 's|^\#Logo=.*$$|Logo=${PREFIX}/share/pixmaps/NetBSD.xpm|g'
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.desktop+=	-e 's|^\#RebootCommand=.*$$|RebootCommand=/sbin/shutdown -r now|g'
SUBST_SED.desktop+=	-e 's|^\#HaltCommand=.*$$|HaltCommand=/sbin/shutdown -p now|g'
.endif

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# The following forces the X server to start on the 5th virtual terminal.
# This is suboptimal but matches the defaults for the xdm configuration,
# which should work for most installations.  See the definition of
# DEFAULTVT in xsrc/xfree/xc/programs/xdm/config/Imakefile.
#
# If we do not do this, we hit a very annoying and obscure problem: during
# system startup, gdm starts before init spawns gettys.  If the X server
# is started before init spawns the gettys (which easily happens on slow
# machines), it grabs the first virtual terminal (instead of the first
# "free" one).  Later on, when the first getty is started, it grabs the
# same terminal X used (the first one).  As a result, only one of them
# will receive key presses.  And on slow machines, X will have lost access
# to the keyboard.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD") && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-authentication-scheme=pam
.  if ${PAM_TYPE} == "linux-pam"
PLIST_SUBST+=		PAM_MISC=""
.  else
PLIST_SUBST+=		PAM_MISC="@comment "
.  endif
.elif exists(/etc/shadow)
CONFIGURE_ARGS+=	--enable-authentication-scheme=shadow
PLIST_SUBST+=		PAM_MISC="@comment "
.else
CONFIGURE_ARGS+=	--enable-authentication-scheme=crypt
PLIST_SUBST+=		PAM_MISC="@comment "
.endif

.if exists(${X11BASE}/include/X11/extensions/dmxext.h)
PLIST_SUBST+=		DMX=""
.else
PLIST_SUBST+=		DMX="@comment "
.endif
PRINT_PLIST_AWK+=	/dmx/ { print "$${DMX}" $$0; next }

.if exists(/usr/include/linux/vt.h)
PLIST_SUBST+=		GDMOPEN=""
.else
PLIST_SUBST+=		GDMOPEN="@comment "
.endif
PRINT_PLIST_AWK+=	/gdmopen/ { print "$${GDMOPEN}" $$0; next }



.include "../../meta-pkgs/modular-xorg-fonts/buildlink3.mk"
.include "../../x11/zenity/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

post-patch:
	cd ${WRKSRC};find po -type f -print0 | xargs -0 gsed -i "s/X11R6/X11R7/"
post-install:
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${DESTDIR}${LOCALBASE}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${DESTDIR}${LOCALBASE}/share/gdm/BuiltInSessions
	(cd ${FILESDIR};tar --exclude CVS -cf - share) | \
		tar xpvf - -C ${DESTDIR}${LOCALBASE}

.include "../../mk/bsd.pkg.mk"


cvs:
	cvs up
	cvs commit
