set(BOARD_EMSK_DIR ${BOARD_ROOT}/emsk)

list(GET SUPPORT_BD_VERSIONS 11 22 23)

get_property(bd_ver_cli_argument CACHE BD_VER PROPERTY VALUE)


## board version
if(${BD_VER})
    if(${BD_VER} IN_LIST SUPPORT_BD_VERSIONS)
    else()
        unset(BD_VER)
    endif()
endif()

foreach(root ${BOARD_ROOT}/emsk)
    find_path(TCF_DIR
    NAMES tcf
    PATHS ${root}/*/*
    NO_DEFAULT_PATH)
endforeach()

if(TCF_DIR)
    set(BOARD_CORE_DIR ${TCF_DIR}/tcf)
endif()

foreach(tcf ${BOARD_CORE_DIR})
    string(REGEX MATCH "^arcem(.*).tcf" SUPPORT_CORE ${tcf})
    if(${SUPPORT_CORE})
        list(APPEND SUPPORT_CORES ${SUPPORT_CORE})
    endif()
endforeach()