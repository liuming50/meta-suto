UBOOT_MACHINE = "qemu_arm_defconfig"
UBOOT_ENTRYPOINT = "0x40080000"

KERNEL_CLASSES = "kernel-suto-fitimage"
KERNEL_IMAGETYPE_qemuarm = "fitImage"

IMAGE_FSTYPES_qemuarm = "wic"

INITRAMFS_IMAGE = "suto-image-initramfs"
INITRAMFS_FSTYPES = "cpio.gz"

IMAGE_BOOT_FILES_qemuarm = "boot.scr"
WKS_FILE_DEPENDS_append = " virtual/bootloader u-boot-default-script"
WKS_FILE = "qemu-vdimage.wks"

# We are using fitimage for qemuarm machine
MACHINE_ESSENTIAL_EXTRA_RDEPENDS_remove = "kernel-devicetree"

QB_MACHINE = "-machine virt"
QB_DRIVE_TYPE = "/dev/vda"
QB_DEFAULT_FSTYPE = "wic"
QB_ROOTFS_OPT = "-drive file=@ROOTFS@,if=sd,format=raw"
QB_MEM_qemuarm = "-m 1057"
QB_OPT_APPEND_qemuarm = "-show-cursor -device VGA,edid=on -device qemu-xhci -device usb-tablet -device usb-kbd -object rng-random,filename=/dev/urandom,id=rng0 -device virtio-rng-pci,rng=rng0 -no-acpi -bios ${DEPLOY_DIR_IMAGE}/u-boot.bin -d unimp"
#QB_OPT_APPEND_qemuarm = "-nographic -object rng-random,filename=/dev/urandom,id=rng0 -device virtio-rng-pci,rng=rng0 -no-acpi -bios ${DEPLOY_DIR_IMAGE}/u-boot.bin -d unimp"

PREFERRED_RPROVIDER_network-configuration_qemuarm = "networkd-static-conf"
PREFERRED_RPROVIDER_u-boot-default-script_qemuarm = "u-boot-suto-boot"
PREFERRED_PROVIDER_u-boot-fw-utils = "libubootenv"
PREFERRED_RPROVIDER_u-boot-fw-utils = "libubootenv"
PREFERRED_RPROVIDER_u-boot-default-env = "u-boot-env"

BBMASK += " \
    /meta-suto/recipes-bsp/u-boot/u-boot-fslc_%.bbappend \
    meta-suto/recipes-kernel/linux/linux-fslc-imx_5.4.bbappend \
"
