BUILD_DIR = ${CURDIR}/gensrc

all: subdirs
.PHONY: all

# build all subdir
SUBDIR = proto thrift
subdirs: ${SUBDIR}
.PHONY: subdirs ${SUBDIR}
${SUBDIR}:
	$(MAKE) -C $@

clean:
	rm -rf ${BUILD_DIR}
.PHONY: clean
