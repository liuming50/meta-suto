FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

REQUIRED_DISTRO_FEATURES_remove = "opengl"

SYSTEMD_SERVICE_${PN} = "weston.service"
SYSTEMD_AUTO_ENABLE = "enable"

do_install_append () {
    rm -rf ${D}${sysconfdir}/udev/rules.d/71-weston-drm.rules
    mv ${D}${systemd_system_unitdir}/weston@.service ${D}${systemd_system_unitdir}/weston.service
}
