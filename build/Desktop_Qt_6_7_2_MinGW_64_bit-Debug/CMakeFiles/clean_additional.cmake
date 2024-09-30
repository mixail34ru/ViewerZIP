# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ViewerZIP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ViewerZIP_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\minizip-ng_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\minizip-ng_autogen.dir\\ParseCache.txt"
  "ViewerZIP_autogen"
  "minizip-ng_autogen"
  )
endif()
