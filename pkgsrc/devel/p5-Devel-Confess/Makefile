# $NetBSD: Makefile,v 1.4 2017/06/05 14:22:51 ryoon Exp $

DISTNAME=	Devel-Confess-0.009001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Confess/
COMMENT=	Include stack traces on all warnings and errors
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Confess/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
