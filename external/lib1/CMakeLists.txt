
# Add a cmake binary taget (in this case, a library)
add_library(lib1 INTERFACE)
target_sources(lib1 INTERFACE lib1.hpp)

#add_library(lib2 INTERFACE lib2.hpp)