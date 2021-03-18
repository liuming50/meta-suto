PACKAGECONFIG_append = " resolved networkd"

DEF_FALLBACK_NTP_SERVERS="pool.ntp.org time.cloudflare.com"
EXTRA_OEMESON += ' \
        -Dntp-servers="${DEF_FALLBACK_NTP_SERVERS}" \
'

# Workaround for some systemd specific udev rules being packaged in
# systemd package while they are needed by initramfs which doesn't
# want install systemd. Please refer to the discussion:
# https://www.mail-archive.com/openembedded-core@lists.openembedded.org/msg140195.html
#
# Fix it by splitting systemd specific udev rules to its own package,
# which could be installed by initramfs.
PACKAGES_prepend = "${PN}-udev-rules "
RDEPENDS_${PN} += "systemd-udev-rules"
FILES_${PN}-udev-rules = " \
    ${rootlibexecdir}/udev/rules.d/70-uaccess.rules \
    ${rootlibexecdir}/udev/rules.d/71-seat.rules \
    ${rootlibexecdir}/udev/rules.d/73-seat-late.rules \
    ${rootlibexecdir}/udev/rules.d/99-systemd.rules \
"

PACKAGE_WRITE_DEPS_append = " ${@bb.utils.contains('DISTRO_FEATURES','systemd','systemd-systemctl-native','',d)}"
pkg_postinst_${PN}_append () {
    if ${@bb.utils.contains('DISTRO_FEATURES','systemd','true','false',d)}; then
        if [ -n "$D" ]; then
            OPTS="--root=$D"
        fi

        # Mask systemd-networkd-wait-online.service to avoid long boot times
        # when networking is unplugged
        systemctl $OPTS mask systemd-networkd-wait-online.service
    fi
}
