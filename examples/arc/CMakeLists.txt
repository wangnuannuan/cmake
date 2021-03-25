
# add_definitions(-D CPU_ARC)
# set(CPU_LIB_ARC obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/libcpuarc.a)

# FILE(GLOB CPU_ARC_ASMSRCS ${EMBARC_OSP}/arc ${EMBARC_OSP}/arc/*s)
# aux_source_directory(${EMBARC_OSP}/arc CPU_ARC_CSRCS)


# add_library(libcpuarc STATIC ${CPU_ARC_ASMSRCS})

## CPU Related ##
# CPU root declaration
set(CPUS_ROOT ${EMBARC_ROOT}/arc)


aux_source_directory(${CPUS_ROOT} CPU_ARC_CSRCS)
embarc_osp_include_directories(
	${EMBARC_ROOT}/arc
	${EMBARC_ROOT}/arc/startup
	${EMBARC_ROOT}/arc/startup
)
aux_source_directory(${EMBARC_ROOT}/arc/startup CPU_ARC_CSRCS)
# find all the source files in the target directories

# extra macros to be defined
add_definitions(-D CPU_ARC)
set(CPU_LIB_ARC obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/libcpuarc.a)
