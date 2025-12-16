cmake_minimum_required(VERSION 3.21)

project (3dtilesplugin)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")

# remember to configure the vcpkg toolchain
find_package(fmt CONFIG REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)


add_library(3dtilesplugin SHARED threeDTilesAction.cpp threeDTilesAction.hpp threeDTilesDialog.h threeDTilesDialog.cpp threeDTilesDialogImpl.h threeDTilesDialogImpl.cpp)
target_link_libraries(3dtilesplugin PRIVATE ifcexplorer_plugin wx::core wx::base ifcdb::ifcdb)


add_custom_command(
    TARGET 3dtilesplugin
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/3dtilesdownloader/dist/main
            $<TARGET_FILE_DIR:3dtilesplugin>
    COMMENT "copy python executable..."
)