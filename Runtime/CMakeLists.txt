set(ASHIBA_PUBLIC
    Public/Test.hpp
)

set(ASHIBA_PRIVATE
    Private/Test.cpp
)

add_library(ashiba_runtime
	STATIC
        ${ASHIBA_PUBLIC}
        ${ASHIBA_PRIVATE}
)

target_include_directories(ashiba_runtime 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(ashiba_runtime PRIVATE assimp::assimp)