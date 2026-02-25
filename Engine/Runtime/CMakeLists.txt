option(ASHIBA_ENABLE_CORE "Build Ashiba Core module" ON)

if(ASHIBA_ENABLE_CORE)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Core)
endif()