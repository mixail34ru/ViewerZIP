# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/minizip-ng/third_party/liblzma"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-build"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/tmp"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/src/liblzma-populate-stamp"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/src"
  "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/src/liblzma-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/src/liblzma-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/_deps/liblzma-subbuild/liblzma-populate-prefix/src/liblzma-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
