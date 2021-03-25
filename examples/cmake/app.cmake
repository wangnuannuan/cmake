function(embarc_osp_sources)
  foreach(arg ${ARGV})
    if(IS_DIRECTORY ${arg})
      message(FATAL_ERROR "embarc_osp_sources() was called on a directory")
    endif()
    target_sources(embarc_osp PRIVATE ${arg})
  endforeach()
endfunction()

macro(embarc_osp_library_named name)
    set(EMBARC_OSP_CURRENT_LIBRARY name)
    add_library(${name} STATIC "")
    set_property(GLOBAL APPEND PROPERTY EMBARC_OSP_LIBS ${name})
    target_link_libraries(${name} PUBLIC embarc_osp_interface)
endmacro()

macro(embarc_osp_interface_library_named name)
  add_library(${name} INTERFACE)
  set_property(GLOBAL APPEND PROPERTY EMBARC_OSP_INTERFACE_LIBS ${name})
endmacro()

macro(embarc_osp_library)
  library_get_current_dir_lib_name(lib_name)
  library_named(${lib_name})
endmacro()

macro(library_get_current_dir_lib_name lib_name)
  file(RELATIVE_PATH name ${EMBARC_OSP} ${CMAKE_CURRENT_LIST_FILE})
  get_filename_component(name ${name} DIRECTORY)
  string(REGEX REPLACE "/" "__" name ${name})
  set(${lib_name} ${name})
endmacro()

function(embarc_osp_library_sources source)
  target_sources(${EMBARC_OSP_CURRENT_LIBRARY} PRIVATE ${source} ${ARGN})
endfunction()

function(embarc_osp_library_include_directories)
  target_include_directories(${EMBARC_OSP_CURRENT_LIBRARY} PRIVATE ${ARGN})
endfunction()

function(compile_options)
  target_compile_options(embarc_osp_interface INTERFACE ${ARGV})
endfunction()

function(embarc_osp_include_directories)
  foreach(arg ${ARGV})
    if(IS_ABSOLUTE ${arg})
      set(path ${arg})
    else()
      set(path ${CMAKE_CURRENT_SOURCE_DIR}/${arg})
    endif()
    target_include_directories(embarc_osp_interface INTERFACE ${path})
  endforeach()
endfunction()

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})

    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

function(add_subdirectory_ifdef feature_toggle dir)
  if(${${feature_toggle}})
    add_subdirectory(${dir})
  endif()
endfunction()

define_property(GLOBAL PROPERTY EMBARC_OSP_LIBS BRIEF_DOCS "all CMake libs that should be linked in" FULL_DOCS  "all CMake libs that should be linked in")
set_property(GLOBAL PROPERTY EMBARC_OSP_LIBS "")

define_property(GLOBAL PROPERTY EMBARC_OSP_INTERFACE_LIBS BRIEF_DOCS "all CMake interfacelibs that should be linked in" FULL_DOCS  "all CMake libs that should be linked in")
set_property(GLOBAL PROPERTY EMBARC_OSP_INTERFACE_LIBS "")

define_property(GLOBAL PROPERTY GENERATED_KERNEL_OBJECT_FILES BRIEF_DOCS "all object file" FULL_DOCS  "all object file")
set_property(GLOBAL PROPERTY GENERATED_KERNEL_OBJECT_FILES "")

define_property(GLOBAL PROPERTY GENERATED_KERNEL_SOURCE_FILES BRIEF_DOCS "source file" FULL_DOCS  "all souce file")
set_property(GLOBAL PROPERTY GENERATED_KERNEL_SOURCE_FILES "")

set(APPLICATION_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Application source dir")
set(APPLICATION_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Application binary dir")
set(__build_dir ${CMAKE_CURRENT_BINARY_DIR}/embarc_osp)
set(PROJECT_BINARY_DIR ${__build_dir})


file(TO_CMAKE_PATH "${EMBARC_OSP}" PROJECT_SOURCE_DIR)

set(EMBARC_OSP_BINARY_DIR ${PROJECT_BINARY_DIR})
set(EMBARC_OSP_BASE ${PROJECT_SOURCE_DIR})
set(ENV{EMBARC_OSP_BASE}   ${EMBARC_OSP})


include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(FATAL_ERROR "Source directory equals build directory.\
 In-source builds are not supported.\
 Please specify a build directory, e.g. cmake -Bbuild -H.")
endif()
set(CMAKE_C_COMPILER_FORCED   1)
set(CMAKE_CXX_COMPILER_FORCED 1)

embarc_osp_library_named(app)
set_property(TARGET app PROPERTY ARCHIVE_OUTPUT_DIRECTORY app)
add_subdirectory(${EMBARC_OSP} ${__build_dir})



# include(${EMBARC_OSP}/options/toolchain/toolchain_gnu.cmake)
include(${EMBARC_OSP}/cmake/options.cmake)
