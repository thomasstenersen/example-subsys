#
# Copyright (c) 2019 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

if (CONFIG_MYPROTO)
  zephyr_library_named(myproto)
  target_sources_ifdef(CONFIG_MYPROTO myproto PRIVATE src/myproto.c)
  zephyr_include_directories(include)

  # Used for exporting
  file(REAL_PATH include/myproto.h public_header)
  set_target_properties(myproto PROPERTIES PUBLIC_HEADER ${public_header})
endif()
