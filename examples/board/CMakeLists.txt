## support boards

define_property(GLOBAL PROPERTY SUPPORT_BOARDS BRIEF_DOCS "all support boards" FULL_DOCS  "all support board")
set_property(GLOBAL PROPERTY SUPPORT_BOARDS "")
file(GLOB_RECURSE BOARD_ROOTS ${CMAKE_CURRENT_SOURCE_DIR} *.cmake)



FOREACH(FILE_PATH ${BOARD_ROOTS})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
    if(FILE_NAME)
    	set_property(GLOBAL APPEND PROPERTY SUPPORT_BOARDS ${FILE_NAME})
    	if(${BOARD} EQUAL ${FILE_NAME})
    		###################3 include source asm
    		#include_directories(${BOARD_ROOT}/${BOARD})
    	endif()
    endif()
ENDFOREACH(FILE_PATH)

get_property(current_board CACHE BOARD PROPERTY VALUE)
get_property(cached_boards_value GLOBAL PROPERTY SUPPORT_BOARDS)

if(current_board) 
	if(${current_board} IN_LIST cached_boards_value)
	else()
		list(GET cached_boards_value 0 current_board)
	endif()

else()
	list(GET cached_boards_value 0 current_board)
endif()
set(BOARD ${BOARD} CACHE STRING "Selected board")
# set(BOARD ${cached_message(${BOARD})
add_definitions(-D EMBARC_USE_BOARD_MAIN)

get_property(current_toolchain CACHE TOOLCHAIN PROPERTY VALUE)
if(${current_toolchain} EQUAL mw)
    set(LINKER_SCRIPT_FILE ${BOARDS_ROOT}/linker_template_mw.ld)
else()
    set(LINKER_SCRIPT_FILE ${BOARDS_ROOT}/linker_template_gnu.ld)
endif()

include(${BOARD_ROOT}/${BOARD}/${BOARD}.cmake)
string(TOUPPER ${BOARD} VALID_BOARD)
add_definitions(-D BOARD_${VALID_BOARD})

if(CPU_FREQ  AND (NOT ${CPU_FREQ} STREQUAL ""))
	add_definitions(-D BOARD_CPU_FREQ=${CPU_FREQ})
endif()

if(DEV_FREQ  AND (NOT ${DEV_FREQ} STREQUAL ""))
	add_definitions(-D BOARD_DEV_FREQ=${DEV_FREQ})
endif()
# add_definitions(-D W_VERSION=22)
# add_subdirectory(${BOARD_ROOT} ${BOARD_ROOT}/${BOARD})



