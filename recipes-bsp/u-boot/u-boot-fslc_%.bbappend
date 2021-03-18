FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append = " \
    file://bootcount.cfg \
    file://bootlimit.cfg \
    file://fitimage.cfg \
"
