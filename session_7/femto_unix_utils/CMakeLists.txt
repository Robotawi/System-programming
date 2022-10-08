cmake_minimum_required(VERSION 3.15)
project(FemtoUnixUtilities)

add_executable(mycp src/mycopy.c)
add_executable(mymv src/mymove.c)
add_executable(myecho src/myecho.c)
add_executable(mypwd src/mycopy.c)

install(TARGETS mycp mymv myecho mypwd DESTINATION bin)

add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
            install_manifest.txt to be uninstalled!
)
