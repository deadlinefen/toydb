set(LIBRARY_OUTPUT_PATH "${BUILD_DIR}/storage")

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cc)

add_library(Storage STATIC ${SRC_FILES})

target_link_libraries(Storage -lrocksdb)