# $NetBSD: Makefile,v 1.14 2017/06/12 12:30:06 maya Exp $
#

DISTNAME=	Data-MessagePack-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-MessagePack/
COMMENT=	MessagePack serialising/deserialising
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Data/MessagePack/.packlist
USE_LANGUAGES=	c99

MAKE_JOBS_SAFE=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
