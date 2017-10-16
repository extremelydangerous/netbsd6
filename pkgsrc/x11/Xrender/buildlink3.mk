# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.Xrender?=	build

BUILDLINK_TREE+=	Xrender

.if !defined(XRENDER_BUILDLINK3_MK)
XRENDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.9.0nb2
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.endif	# XRENDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xrender
