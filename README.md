# meta-suto
OpenEmbedded/Yocto BSP SUTO layer


# Dependencies

```
URI: git://git.openembedded.org/openembedded-core.git
branch: dunfell
revision: HEAD

URI: git://git.openembedded.org/bitbake.git
branch: 1.46
revision: HEAD

URI: git://git.openembedded.org/meta-openembedded.git
branch: dunfell
revision: HEAD

URI: git://github.com/Freescale/meta-freescale.git
branch: dunfell
revision: HEAD

URI: git://github.com/Freescale/meta-freescale-3rdparty.git
branch: dunfell
revision: HEAD

URI: git://github.com/Freescale/meta-freescale-distro.git
branch: dunfell
revision: HEAD

URI: git://code.qt.io/yocto/meta-qt6.git
branch: 6.1
revision: HEAD

URI: git://github.com/mendersoftware/meta-mender.git
branch: dunfell
revision: HEAD

URI: git://github.com/mendersoftware/meta-mender-community.git
branch: dunfell
revision: HEAD

URI: git://git.yoctoproject.org/meta-security.git
branch: dunfell
revision: HEAD

URI: git://git.yoctoproject.org/meta-virtualization.git
branch: dunfell
revision: HEAD

```


# Getting started

meta-suto consist of multiple Git repositories and repo is the tool that makes it easier to work with those repositories as a whole. Create a local bin/ directory, download the repo tool to that directory, and allow the binary executable with the following commands:

```
$ make -p ~/bin
$ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
$ chmod a+x ~/bin/repo
$ export PATH=~/bin:$PATH
```


# Download the source

Create an empty directory that will hold the meta-suto and Yocto source files and serve as the working directory. Enter the following commands to bring down the latest version of repo tool, including its most recent fixes. The URL specifies the manifest that refers various repositories used by meta-suto, which are placed within the working directory. For now, a .repo folder is created to store the manifest and the metadata of the source repositories.


```
$ mkdir ~/suto-workspace
$ cd ~/suto-workspace
$ repo init -u https://test-en.suto-soft.com/S332/suto-manifests.git -b master
```


Enter the following command to pull down the source tree to your working directory. The repo sync operation might take time depending on your Internet download speed.

```
$ repo sync
```


# Build the source natively (Verified only on Ubuntu 16.04/18.04/20.04)

Set up the environment:

```
$ cd ~/suto-workspace
$ . poky-init-build-env
$ bitbake suto-image-weston
```

or build a X11 image:
```
$ cd ~/suto-workspace
$ . poky-init-build-env
$ DISTRO=suto-x11 bitbake suto-image-x11
```

After a successful build, the artifacts could be found in deploy directory:

In ~/suto-workspace/build-nxp/tmp-glibc/deploy/images/imx6ullevk
```
suto-image-weston-imx6ullevk.wic.gz: Image (after decompressed) could be flashed to a SDCard or EMMC device.
```

or for qemuarm:
In ~/suto-workspace/build-qemu/tmp-glibc/deploy/images/qemuarm
```
suto-image-weston-qemuarm.wic: Image could be launched in qemu.
```


# Connect to the device

Both nxp and qemuarm machines support SSH and VNC connections for debug

For qemuarm:

Start qemu machine:

```
$ runqemu qemuarm
```

Connect to qemu machine by SSH:

```
$ ssh root@192.168.7.2
```

Connect to qemu machine by VNC:

```
$ xtightvncviewer 127.0.0.1
```

For nxp machine:

Same with qemuarm, but change the connection address to the IP of the target.



# Set up SUTO SDK (On any Linux distributions, Debian, Ubuntu, Fedora, Readhat, ArchLinux...)

Build SDK:

```
$ bitbake suto-image-weston -c populate_sdk
```

Install SDK:

```
$ ~/suto-workspace/build-nxp/tmp-glibc/deploy/sdk/oecore-x86_64-cortexa7t2hf-neon-toolchain-suto.0.sh -y -d ~/suto-sdk
```

Set up SDK:

```
$ unset LD_LIBRARY_PATH
$ source ~/suto-sdk/environment-setup-cortexa7t2hf-neon-suto-linux-gnueabi
```

Now you have CC, CXX, CPP, CFLAGS, CXXFLAGS, LDFALGS, qt-cmake in your environment:

```
$ $CXX --version
arm-suto-linux-gnueabi-g++ (GCC) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Build a QT6 project within SDK

```
$ git clone git://code.qt.io/qt/qtbase.git
$ cd qtbase
$ git checkout -b 6.1 origin/6.1
$ cd examples/widgets/animation
$ qt-cmake
```

Layer Maintainer: [Ming Liu](<mailto:liu.ming50@gmail.com>)
