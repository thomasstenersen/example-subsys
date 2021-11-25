#
# Copyright (c) 2021 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(NONE)

# FIXME: Zephyr does not support building only a static library, it will always
# build an `app` target. Therefore we add an empty source file to the target to
# please the build system.
target_sources(app PRIVATE ${ZEPHYR_BASE}/misc/empty_file.c)

if(CONFIG_FP_SOFTABI)
  set(FPU_ABI softfp-float)
elseif(CONFIG_FP_HARDABI)
  set(FPU_ABI hard-float)
else()
  set(FPU_ABI soft-float)
endif()

# Setup of CMake install target
install(
  TARGETS myproto
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${GCC_M_CPU}/${FPU_ABI}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  )
