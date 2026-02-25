set(ASHIBA_CORE_HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Public")
set(ASHIBA_CORE_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Private")

set(ASHIBA_CORE_HEADERS
    ${ASHIBA_CORE_HEADERS_DIR}/Misc.hpp
    ${ASHIBA_CORE_HEADERS_DIR}/Misc/Defines.hpp
    ${ASHIBA_CORE_HEADERS_DIR}/Misc/Types.hpp
)

if(NOT DEFINED ASHIBA_RUNTIME_GENERATED_INCLUDE_DIR)
    set(ASHIBA_RUNTIME_GENERATED_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/Include")
endif()

set(ASHIBA_CORE_GENERATED_INCLUDE_DIR "${ASHIBA_RUNTIME_GENERATED_INCLUDE_DIR}/Ashiba/Core")

foreach(header_file IN LISTS ASHIBA_CORE_HEADERS)
    file(RELATIVE_PATH rel_header_file "${ASHIBA_CORE_HEADERS_DIR}" "${header_file}")
    file(TO_CMAKE_PATH "${rel_header_file}" rel_header_file)

    set(alias_header_file "${ASHIBA_CORE_GENERATED_INCLUDE_DIR}/${rel_header_file}")
    get_filename_component(alias_header_dir "${alias_header_file}" DIRECTORY)
    file(MAKE_DIRECTORY "${alias_header_dir}")

    set(alias_header_content "#pragma once\n#include <${rel_header_file}>\n")

    if(EXISTS "${alias_header_file}")
        file(READ "${alias_header_file}" existing_alias_header_content)
        if(existing_alias_header_content STREQUAL alias_header_content)
            continue()
        endif()
    endif()

    file(WRITE "${alias_header_file}" "${alias_header_content}")
endforeach()

set(ASHIBA_CORE_SOURCES
    ${ASHIBA_CORE_SOURCES_DIR}/Placeholder.cpp
)

if(ASHIBA_BUILD_SHARED)
    add_library(ashiba_core SHARED)
else()
    add_library(ashiba_core STATIC)
endif()

target_sources(ashiba_core
    PRIVATE
        ${ASHIBA_CORE_SOURCES}
    PUBLIC
        ${ASHIBA_CORE_HEADERS}
)

target_include_directories(ashiba_core
    PUBLIC
        $<BUILD_INTERFACE:${ASHIBA_CORE_HEADERS_DIR}>
        $<BUILD_INTERFACE:${ASHIBA_RUNTIME_GENERATED_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:Include/Ashiba>
)

include(GNUInstallDirs)

install(DIRECTORY "${ASHIBA_CORE_HEADERS_DIR}/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Ashiba
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)

install(DIRECTORY "${ASHIBA_CORE_GENERATED_INCLUDE_DIR}/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Ashiba/Core
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)