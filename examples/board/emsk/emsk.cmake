list(GET SUPPORT_BD_VERSIONS 11 22 23)
get_property(board_version CACHE BD_VER PROPERTY VALUE)

if(board_version)
endif()


set(BOARD_EMSK_DIR ${BOARD_ROOT}/emsk)



# set(CACHED_BD_VER ${BD_VER} CACHE STRING "Selected board version")
# if(NOT CACHE_BD_VER)

# endif()

set(BD_VER 22 CACHE STRING "Selected board version")
set(CUR_CORE arcem7d CACHE STRING "Selected board version")

## board version
if(BD_VER)
    if(${BD_VER} IN_LIST SUPPORT_BD_VERSIONS)
    else()
        unset(BD_VER)
    endif()
endif()
## find tcf dir
# FILE(GLOB chdiren RELATIVE ${BOARD_ROOT}/emsk ${BOARD_ROOT}/emsk/*) ## not for emsdp
# foreach(root ${chdiren})
#     find_path(TCF_DIR
#     NAMES tcf
#     PATHS ${BOARD_ROOT}/emsk/${root}/*
#     NO_DEFAULT_PATH)
#     if(TCF_DIR)
        
#         FILE(GLOB chdiren RELATIVE ${BOARD_ROOT}/emsk/${root} ${BOARD_ROOT}/emsk/${root}/*)
#         if(${BD_VER} IN_LIST ${chdiren})
#             set(TCF_DIR ${BOARD_ROOT}/emsk/${root}/${BD_VER}) 
#         endif()
#         break()
#     endif()
#     # string(FIND ${TCF_DIR} ${BD_VER} find_tcf_dir)
#     # if(${find_tcf_dir} GREATER_EQUAL -1)
#     #     set(TCF_DIR ${TCF_DIR})
#     #     break()
#     # else()
#     #     continue()
#     # endif()
# endforeach()
# if(TCF_DIR)
#     set(BOARD_CORE_DIR ${TCF_DIR}/tcf)
# endif()
set(BOARD_CORE_DIR /home/wang/Documents/PythonLearn/board/emsk/configs/22/tcf)
FILE(GLOB chdiren RELATIVE ${BOARD_CORE_DIR} ${BOARD_CORE_DIR}/*)
foreach(tcf ${chdiren})
    string(REGEX REPLACE ".tcf" "" SUPPORT_CORE ${tcf})
    if(SUPPORT_CORE)
        list(APPEND SUPPORT_CORES ${SUPPORT_CORE})
    endif()
    if(CUR_CORE IN_LIST SUPPORT_CORES)
        set(VALID_TCF ${BOARD_CORE_DIR}/${tcf} CACHE STRING "Selected board core")
    endif()
endforeach()

### core_config.mk

### core_config.mk 
# set(HEADER_FILES ${BOARD_ROOT}/emsk/emsk.h)
compile_options(
  -include ${BOARD_ROOT}/emsk/emsk.h
  )
# set(HEADER_FILES ${BOARD_ROOT}/emsk/emsk.h)

#embarc_osp_library()
# embarc_osp_library()


embarc_osp_include_directories(${BOARD_ROOT}/emsk/configs/${BD_VER})

if(${BD_VER} STREQUAL "23")
    add_definitions(-D CORE_DMAC_INTERNAL_VERSION=2)
endif()

define_property(GLOBAL PROPERTY ONCHIP_IP_LIST BRIEF_DOCS "all support boards" FULL_DOCS  "all support board")
set_property(GLOBAL PROPERTY ONCHIP_IP_LIST "")
set(onchip_ip_list designware/iic designware/spi designware/uart designware/gpio)
foreach(ip ${onchip_ip_list})
    set_property(GLOBAL APPEND PROPERTY ONCHIP_IP_LIST ${ip})
endforeach()
# set_property(GLOBAL PROPERTY ONCHIP_IP_LIST designware/iic designware/spi designware/uart designware/gpio)
