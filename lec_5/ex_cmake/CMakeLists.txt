cmake_minimum_required (VERSION 3.7)
project(progy)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES src/myadd.c  src/mydiv.c  src/mymul.c  src/mysub.c  src/prog.c)
add_executable(progy ${PROJECT_SOURCE_DIR}/${SOURCES})

install(TARGETS progy DESTINATION /usr/bin)

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mohamed Raessa")
include(CPack)

