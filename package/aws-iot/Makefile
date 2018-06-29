#
# Copyright (C) 2007-2008 Delta Networks Inc.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=aws-iot
PKG_VERSION:=1.0
PKG_RELEASE:=1
PKG_BUILD_DEPENDS:=datalib

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

PKG_GIT_TREEISH:=e2346eec2dc4876ef298d8c819cbb7141ce53d50

include $(INCLUDE_DIR)/package.mk

define Package/aws-iot
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=The AWS IoT to Publish Topic
endef

define Build/Prepare
	$(CP) $(GIT_HOME)/aws-iot.git/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
       $(CP) ./files/* $(PKG_BUILD_DIR)/files
endef

define Build/Configure
endef

define Package/aws-iot/install
	install -d -m0755 $(1)/usr/sbin
	install -d -m0755 $(1)/etc/init.d
	install -d -m0755 $(1)/etc/rc.d
	install -d -m0755 $(1)/etc/router_analytics
	install -d -m0755 $(1)/etc/router_analytics/beta
	install -d -m0755 $(1)/etc/router_analytics/debug
	install -m0755 $(PKG_BUILD_DIR)/files/aws-iot.init $(1)/etc/init.d/aws
	install -m0755 $(PKG_BUILD_DIR)/files/certs/certificate.pem.crt  $(1)/etc/router_analytics/
	install -m0755 $(PKG_BUILD_DIR)/files/certs/rootCA.crt $(1)/etc/router_analytics
	install -m0755 $(PKG_BUILD_DIR)/files/certs/beta/certificate.pem.crt  $(1)/etc/router_analytics/beta/
	install -m0755 $(PKG_BUILD_DIR)/files/certs/beta/rootCA.crt $(1)/etc/router_analytics/beta/
	install -m0755 $(PKG_BUILD_DIR)/files/certs/beta/rootCA.crt $(1)/etc/router_analytics/beta/
	install -m0755 $(PKG_BUILD_DIR)/files/certs/debug/rootCA.crt $(1)/etc/router_analytics/debug/
	install -m0755 $(PKG_BUILD_DIR)/files/certs/debug/certificate.pem.crt  $(1)/etc/router_analytics/debug
	install -m0755 $(PKG_BUILD_DIR)/icqm  $(1)/usr/sbin
	install -m0755 $(PKG_BUILD_DIR)/ra_check  $(1)/usr/sbin
	ln -sv ../init.d/aws $(1)/etc/rc.d/S99zzaws
endef

$(eval $(call BuildPackage,aws-iot))
