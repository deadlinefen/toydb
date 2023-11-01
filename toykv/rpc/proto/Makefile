BUILD_DIR = ${CURDIR}/../gensrc

PROTOC = /usr/local/bin/protoc

SOURCES = $(shell find ${CURDIR} -name "*.proto")
OBJECTS = $(patsubst ${CURDIR}/%.proto, ${BUILD_DIR}/%.pb.cc, ${SOURCES})
HEADERS = $(patsubst ${CURDIR}/%.proto, ${BUILD_DIR}/%.pb.h, ${SOURCES})

all: ${OBJECTS} ${HEADERS}
.PHONY: all

${BUILD_DIR}/%.pb.h ${BUILD_DIR}/%.pb.cc: ${CURDIR}/%.proto | ${BUILD_DIR}
	${PROTOC} --proto_path=${CURDIR} --cpp_out=${BUILD_DIR} $<

${BUILD_DIR}:
	mkdir -p $@

