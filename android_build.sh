export HOST_ARCH=$(uname -m)
export HOST_OS=$(uname -s | tr '[:upper:]' '[:lower:]')
export TARG_ARM=arm
export AND_API=24
export AND_VER=4.9
export AND_TRI=${TARG_ARM}-linux-androideabi
export SYSROOT=${NDK_HOME}/platforms/android-${AND_API}/arch-${TARG_ARM}/
export TOOLCHAIN=${NDK_HOME}/toolchains/${AND_TRI}-${AND_VER}/prebuilt/${HOST_OS}-${HOST_ARCH}/
export NDK_BIN=${TOOLCHAIN}/${AND_TRI}/bin
export CC=${TOOLCHAIN}/bin/${AND_TRI}-gcc
export CXX=${TOOLCHAIN}/bin/${AND_TRI}-c++
export LIBDIR=${SYSROOT}/usr/lib/
export INCLUDEDIR=${SYSROOT}/usr/include/
export PATH="${NDK_BIN}:${PATH}:${NDK_BIN}"
export PKG_CONFIG_PATH=${SYSROOT}/usr/lib/pkgconfig
./build.sh
