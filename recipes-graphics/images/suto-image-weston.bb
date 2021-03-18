require recipes-graphics/images/core-image-weston.bb
require suto-image-common.inc

CORE_IMAGE_BASE_INSTALL_remove = "weston-examples gtk+3-demo clutter-1.0-examples"

CORE_IMAGE_BASE_INSTALL_append = " \
    qtwayland \
"
