SPLASH = "plymouth"

IMAGE_FEATURES += "splash hwcodecs ssh-server-openssh"

RM_WORK_EXCLUDE += "${PN}"

WIC_CREATE_EXTRA_ARGS_append = " --no-fstab-update"

CORE_IMAGE_BASE_INSTALL_append = " \
    kernel-modules \
    network-configuration \
    qtbase-examples \
    qtmqtt-examples \
    u-boot-fw-utils \
    zram \
"

# Check initramfs bundled fitimage, copy it to rootfs if it's present in
# ${DEPLOY_DIR_IMAGE}
check_initramfs_bundled_fitimage() {
    if [ -n "${INITRAMFS_IMAGE}" ]; then
        if [ -e ${DEPLOY_DIR_IMAGE}/fitImage-${INITRAMFS_IMAGE}-${MACHINE}-${MACHINE} ]; then
            rm -rf ${IMAGE_ROOTFS}/boot/fitImage*
            install -m 0644 ${DEPLOY_DIR_IMAGE}/fitImage-${INITRAMFS_IMAGE}-${MACHINE}-${MACHINE} ${IMAGE_ROOTFS}/boot/fitImage
        fi
    fi
}

# Copy initramfs bundled fitimage to rootfs if it's present
ROOTFS_POSTPROCESS_COMMAND += "check_initramfs_bundled_fitimage ; "

inherit populate_sdk_qt6_base

TOOLCHAIN_HOST_TASK_append = " nativesdk-packagegroup-qt6-toolchain-host"
TOOLCHAIN_TARGET_TASK_append = " packagegroup-qt6-toolchain-target"
