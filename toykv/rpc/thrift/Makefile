BUILD_DIR = ${CURDIR}/../gensrc
THRIFT_DIR = ${CURDIR}

THRIFT = /usr/local/bin/thrift

SOURCES = $(shell find ${THRIFT_DIR} -name "*.thrift")
OBJECTS = $(patsubst ${THRIFT_DIR}/%.thrift, ${BUILD_DIR}/%_types.cpp, ${SOURCES})

GEN_SOURCES = $(shell find ${THRIFT} -name "*.thrift")
GEN_OBJECTS = $(patsubst ${BUILD_DIR}/thrift/%.thrift, ${BUILD_DIR}/%_types.cpp, ${GEN_SOURCES})

all: ${GEN_OBJECTS} ${OBJECTS}
.PHONY: all


THRIFT_CPP_ARGS = -I ${THRIFT_DIR} -I ${BUILD_DIR}/thrift/ --gen cpp -out ${BUILD_DIR} --allow-64bit-consts -strict

${BUILD_DIR}:
	mkdir -p $@

# handwrite thrift
${BUILD_DIR}/%_types.cpp: ${THRIFT_DIR}/%.thrift | ${BUILD_DIR}
	${THRIFT} ${THRIFT_CPP_ARGS} $<

# generated thrift
${BUILD_DIR}/%_types.cpp: ${BUILD_DIR}/thrift/%.thrift | ${BUILD_DIR}
	${THRIFT} ${THRIFT_CPP_ARGS} $<