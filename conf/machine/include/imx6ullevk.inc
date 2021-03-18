IMX_DEFAULT_BSP = "mainline"

# Explicitly use fitimage
KERNEL_CLASSES_append = " kernel-suto-fitimage"
KERNEL_IMAGETYPE_imx6ullevk = "fitImage"

SOC_DEFAULT_IMAGE_FSTYPES = "wic"
WKS_FILE_DEPENDS_append = " u-boot-default-script"

IMAGE_BOOT_FILES_append = " boot.scr"
IMAGE_BOOT_FILES_remove = "${KERNEL_IMAGETYPE} ${@make_dtb_boot_files(d)}"

INITRAMFS_IMAGE = "suto-image-initramfs"
INITRAMFS_FSTYPES = "cpio.gz"

PREFERRED_RPROVIDER_u-boot-default-script_imx6ullevk_= "u-boot-suto-boot"
PREFERRED_PROVIDER_u-boot-fw-utils = "libubootenv"
PREFERRED_RPROVIDER_u-boot-fw-utils = "libubootenv"
PREFERRED_RPROVIDER_u-boot-default-env = "u-boot-fslc-env"
