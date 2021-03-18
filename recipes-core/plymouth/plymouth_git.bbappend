FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

SRC_URI += " \
    file://sutologo-white.png \
    file://spinner.plymouth \
"

PACKAGECONFIG = "pango drm"

do_install_append () {
    install -m 0644 ${WORKDIR}/sutologo-white.png ${D}${datadir}/plymouth/themes/spinner/watermark.png
    install -m 0644 ${WORKDIR}/spinner.plymouth ${D}${datadir}/plymouth/themes/spinner/spinner.plymouth
}
