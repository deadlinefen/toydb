set(LIBRARY_OUTPUT_PATH "${BUILD_DIR}/rpc")

set (GEN_CPP_DIR ${BASE_DIR}/rpc/gensrc)
file(GLOB SRC_FILES CONFIGURE_DEPENDS
    ${GEN_CPP_DIR}/*.cpp
    ${GEN_CPP_DIR}/*.cc
)

add_compile_options(-Wno-return-type)

# keep everything in one library, the object files reference 
# each other
add_library(Rpc STATIC ${SRC_FILES})