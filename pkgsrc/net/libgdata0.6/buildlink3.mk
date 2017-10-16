# $NetBSD: buildlink3.mk,v 1.5 2017/04/22 21:03:15 adam Exp $

BUILDLINK_TREE+=	libgdata06

.if !defined(LIBGDATA06_BUILDLINK3_MK)
LIBGDATA06_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata06+=	libgdata>=0.6.4<0.16
BUILDLINK_ABI_DEPENDS.libgdata06+=	libgdata>=0.6.6nb21
BUILDLINK_PKGSRCDIR.libgdata06?=	../../net/libgdata0.6

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

.endif	# LIBGDATA06_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata06
