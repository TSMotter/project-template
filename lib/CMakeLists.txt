set(gm_lib_source_files
   ${CMAKE_CURRENT_SOURCE_DIR}/gm_lib.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/gm_lib.hpp
)

add_library(gm_lib INTERFACE)
target_sources(gm_lib INTERFACE ${gm_lib_source_files})

# Make the directory known
target_include_directories(gm_lib INTERFACE ${CMAKE_SOURCE_DIR}/external/lib1)

# Link library to a binary target
target_link_libraries(gm_lib INTERFACE lib1)