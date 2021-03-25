message("libc")
set(LIB_CLIB_DIR ${EMBARC_OSP}/library/clib)

aux_source_directory(${LIB_CLIB_DIR} LIB_CLIB_CSRCS)
embarc_osp_sources(
	${LIB_CLIB_CSRCS}
	)

embarc_osp_include_directories(
	${LIB_CLIB_DIR}
)

add_definitions(-D LIB_CLIB)

add_definitions(-DHAVE_MMAP=0 -DHAVE_MREMAP=0 -DMMAP_CLEARS=0 -DLACKS_SYS_PARAM_H)

# set(LIB_CLIB_ASMSRCS obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/libcpuarc.a)

FILE(GLOB CPU_ARC_ASMSRCS ${LIB_CLIB_DIR} ${LIB_CLIB_DIR}/*s)
# aux_source_directory(${EMBARC_OSP}/arc CPU_ARC_CSRCS)


add_library(liblibclib STATIC ${LIB_CLIB_CSRCS} ${CPU_ARC_ASMSRCS})