DESCRIPTION = "SUTO initramfs image"

PACKAGE_INSTALL = "initramfs-framework-base initramfs-module-udev \
    initramfs-module-rootfs initramfs-module-debug \
    initramfs-module-plymouth ${VIRTUAL-RUNTIME_base-utils} base-passwd"

SYSTEMD_DEFAULT_TARGET = "initrd.target"

# Do not pollute the initrd image with rootfs features
IMAGE_FEATURES = "splash"

export IMAGE_BASENAME = "suto-image-initramfs"
IMAGE_LINGUAS = ""

LICENSE = "MIT"

ROOTFS_POSTPROCESS_COMMAND_remove = "mender_update_fstab_file; mender_create_scripts_version_file;"

IMAGE_FSTYPES_forcevariable = "cpio.gz"
IMAGE_FSTYPES_remove = "wic wic.gz wic.bmap wic.vmdk wic.vdi ext4 ext4.gz"
IMAGE_CLASSES_remove = "image_types_fsl license_image qemuboot"

# avoid circular dependencies
EXTRA_IMAGEDEPENDS = ""

inherit core-image nopackages

IMAGE_ROOTFS_SIZE = "8192"

# Users will often ask for extra space in their rootfs by setting this
# globally.  Since this is a initramfs, we don't want to make it bigger
IMAGE_ROOTFS_EXTRA_SPACE = "0"
IMAGE_OVERHEAD_FACTOR = "1.0"

BAD_RECOMMENDATIONS += "busybox-syslog"
