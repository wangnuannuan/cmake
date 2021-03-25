cmake_minimum_required(VERSION 3.13.1)

set(EMBARC_OSP /home/wang/Documents/PythonLearn)
set(BOARD_ROOT ${EMBARC_OSP}/board)
file(TO_CMAKE_PATH "${ZEPHYR_BASE}" PROJECT_SOURCE_DIR)

include(${EMBARC_OSP}/cmake/app.cmake)
# embarc_osp_include_directories(${EMBARC_OSP}/inc)
# embarc_osp_include_directories(${EMBARC_OSP}/inc/arc)
# embarc_osp_include_directories(${EMBARC_OSP}/board)
# embarc_osp_include_directories(${EMBARC_OSP}/board/emsk) 
# embarc_osp_include_directories(${EMBARC_OSP}/device/ip/ip_hal/inc) 
# embarc_osp_include_directories(${EMBARC_OSP}/device/inc) 
# embarc_osp_include_directories(${EMBARC_OSP}/device/ip/designware/gpio)
set(TOOLCHAIN gnu)
# specifies -DBOARD= on the command line



# link_libraries() #添加需要链接的库文件路径
project(blinky)


# show incldue dir 
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
    message(STATUS "include dir='${dir}'")
endforeach()
# target_sources(app PRIVATE main.c)
# add_executable(Blinky main.c)
message(STATUS "include dir='${HEADER_FILES}'")
#add_executable(Blinky main.c ${HEADER_FILES})
target_sources(app PRIVATE main.c)