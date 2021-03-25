toolchain_cc_optimize_for_no_optimizations_flag(OPTIMIZE_FOR_NO_OPTIMIZATIONS_FLAG)
toolchain_cc_optimize_for_debug_flag(OPTIMIZE_FOR_DEBUG_FLAG)
toolchain_cc_optimize_for_speed_flag(OPTIMIZE_FOR_SPEED_FLAG)
toolchain_cc_optimize_for_size_flag(OPTIMIZE_FOR_SIZE_FLAG)


# @Intent: Obtain compiler specific flags for compiling under different ISO standards of C++
toolchain_cc_cpp_dialect_std_98_flags(CPP_DIALECT_STD_98_FLAGS)
toolchain_cc_cpp_dialect_std_11_flags(CPP_DIALECT_STD_11_FLAGS)
toolchain_cc_cpp_dialect_std_14_flags(CPP_DIALECT_STD_14_FLAGS)
toolchain_cc_cpp_dialect_std_17_flags(CPP_DIALECT_STD_17_FLAGS)
toolchain_cc_cpp_dialect_std_2a_flags(CPP_DIALECT_STD_2A_FLAGS)

# @Intent: Set compiler specific flags for standard C includes
toolchain_cc_nostdinc()

# @Intent: Set compiler specific macro inclusion of AUTOCONF_H
#toolchain_cc_imacros(${AUTOCONF_H})

# @Intent: Set compiler specific flag for bare metal freestanding option
toolchain_cc_freestanding()

# @Intent: Set compiler specific flag for tentative definitions, no-common
toolchain_cc_nocommon()
# @Intent: Obtain compiler specific flags related to assembly
toolchain_cc_asm_base_flags(ASM_BASE_FLAG)

add_definitions(-D CPU_ARC)
set(CPU_LIB_ARC obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/libcpuarc.a)

FILE(GLOB CPU_ARC_ASMSRCS ${EMBARC_OSP}/arc ${EMBARC_OSP}/arc/*s)
aux_source_directory(${EMBARC_OSP}/arc CPU_ARC_CSRCS)


add_library(libcpuarc STATIC ${CPU_ARC_ASMSRCS})