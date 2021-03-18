FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append_qemuarm = " \
    file://0001-fat-check-for-buffer-size-before-reading-blocks.patch \
    file://bootcount.cfg \
    file://bootlimit.cfg \
    file://fitimage.cfg \
    file://ext4env.cfg \
    file://fw_env.config \
"
