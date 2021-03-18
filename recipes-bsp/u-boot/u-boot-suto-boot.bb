DESCRIPTION = "Boot script for launching images with U-Boot distro boot"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS = "u-boot-mkimage-native"

SRC_URI = " \
    file://boot.cmd.in \
"

inherit deploy nopackages

PROVIDES += "u-boot-default-script"

do_deploy() {
    mkimage -T script -C none -n "Distro boot script" -d ${WORKDIR}/boot.cmd.in boot.scr
    install -m 0644 boot.scr ${DEPLOYDIR}
}

addtask deploy after do_install before do_build

PACKAGE_ARCH = "${MACHINE_ARCH}"
