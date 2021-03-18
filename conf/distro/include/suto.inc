MAINTAINER = "Ming Liu <liu.ming50@gmail.com>"

TARGET_VENDOR = "-suto"

SDK_VENDOR = "-suto"
SDK_VERSION = "suto.0"

DISTROOVERRIDES .= ":suto"

# Set default network configuration
PREFERRED_RPROVIDER_network-configuration = "networkmanager"

DISTRO_VERSION = "1.0.0"
DISTRO_FEATURES_remove = "ptest"
DISTRO_FEATURES_append = " pam systemd"

VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
VIRTUAL-RUNTIME_initscripts = ""

# SUTO Yocto does not use runtime package management, so version numbers going
# backwards are not a problem for us.
ERROR_QA_remove = "version-going-backwards"

require conf/distro/include/qt6.inc
