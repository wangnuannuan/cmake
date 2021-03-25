
set(GENE_TCF arc.tcf)

set(GENE_BCR_CONTENTS_TXT bcr_contents.txt)
##
# Argument files' filename generated from TCF
# Don't do any modification here
##
set(GENE_CCAC_ARG ccac.arg)
set(GENE_GCC_ARG gcc.arg)
set(GENE_NSIM_PROPS nsim.props)
set(GENE_MDB_ARG mdb.arg)
set(GENE_CORE_CONFIG_H core_config.h)

set(GENE_CORE_CONFIG_S core_config.s)
##
# Apex possiblely not generated
##
set(GENE_APEXEXTENSIONS_H apexextensions.h)
set(GENE_APEXEXTENSIONS_S apexextensions.s)

##
# Argument files not generated
##
set(GENE_LINK_CMD_TXT mw_linker.ld)
set(GENE_MEMORY_X gnu_linker.ld)
list(GET GENE_FILE_LIST ${GENE_TCF} ${GENE_CCAC_ARG} ${GENE_GCC_ARG} ${GENE_NSIM_PROPS} ${GENE_MDB_ARG} ${GENE_CORE_CONFIG_H} ${GENE_CORE_CONFIG_S})
##
# Output Directory Set
##
if(NOT OUT_DIR_ROOT)
	set(OUT_DIR_PREFIX obj_)
else()
	if(IS_DIRECTORY ${OUT_DIR_ROOT})
		set(OUT_DIR_PREFIX ${OUT_DIR_ROOT}/obj_)
	else()
		set(OUT_DIR_PREFIX obj_)
	endif()
endif()
#include(${EMBARC_OSP}/cmake/scripts.cmake)

# add_custom_command()
set(APPL_NAME app_${TOOLCHAIN}_${CUR_CORE})
set(APPL_FULL_NAME obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/${APPL_NAME})
set(APPL_OUT_DIR obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/application)
set(EMBARC_GENERATED_DIR obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/embARC_generated)
set(APPL_LINK_FILE obj_${BOARD}_${BD_VER}/${TOOLCHAIN}_${CUR_CORE}/linker_${TOOLCHAIN}.ldf)

set(CACHED_BOARD ${BOARD} CACHE STRING "Selected board")

set(CACHED_BD_VER ${BD_VER} CACHE STRING "Selected board")
include(${EMBARC_OSP}/cmake/rules.cmake)
include(${EMBARC_OSP}/cmake/toolchain.cmake)