set(ASHIBA_CORE_PUBLIC
    Public/Ashiba/Core/Test.h
)

set(ASHIBA_CORE_PRIVATE
    Private/Core/Test.cpp
)

add_library(ashiba_runtime_core
	STATIC
        ${ASHIBA_CORE_PUBLIC}
        ${ASHIBA_CORE_PRIVATE}
)

target_include_directories(ashiba_runtime_core 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/Public/Ashiba
        ${CMAKE_CURRENT_SOURCE_DIR}/Public/Ashiba/Core
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Private/Ashiba
        ${CMAKE_CURRENT_SOURCE_DIR}/Private/Ashiba/Core
)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(ashiba_runtime_core PRIVATE assimp::assimp)

set_target_properties(ashiba_runtime_core 
    PROPERTIES
        OUTPUT_NAME "Ashiba_Core"
)