
# add_definitions(-D CPU_ARC)
# set(CPU_LIB_ARC obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/libcpuarc.a)

# FILE(GLOB CPU_ARC_ASMSRCS ${EMBARC_OSP}/arc ${EMBARC_OSP}/arc/*s)
# aux_source_directory(${EMBARC_OSP}/arc CPU_ARC_CSRCS)


# add_library(libcpuarc STATIC ${CPU_ARC_ASMSRCS})