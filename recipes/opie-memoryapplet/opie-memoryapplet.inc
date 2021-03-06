DESCRIPTION = "Memory Applet. \
This applet displays the amount of free memory and manages the swap partition"
SECTION = "opie/applets"
PRIORITY = "optional"
LICENSE = "GPL"
APPNAME = "memoryapplet"

S = "${WORKDIR}/memoryapplet"

inherit opie

pkg_postinst() {
#!/bin/sh
if [ -n "$D" ]; then exit 1; fi
if pidof -s qpe >/dev/null; then
  ${bindir}/qcop QPE/TaskBar "reloadApplets()"
fi
}

pkg_postrm() {
#!/bin/sh
${bindir}/qcop QPE/TaskBar "reloadApplets()"
 if [ -n "$D" ]; then false; fi
}

do_install() {
    install -d ${D}${palmtopdir}/plugins/applets ${D}${palmtopdir}/pics/memory/
    install -m 0644 ${WORKDIR}/pics/memory/*.png ${D}${palmtopdir}/pics/memory/
    oe_libinstall -so libmemoryapplet ${D}${palmtopdir}/plugins/applets/
}

