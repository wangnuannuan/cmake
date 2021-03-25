enable_language(C CXX ASM)

check_c_compiler_flag("" toolchain_is_ok)


set(CMAKE_EXECUTABLE_SUFFIX .elf)

# Set some phony targets to collect dependencies
set(OFFSETS_H_TARGET           offsets_h)
set(SYSCALL_MACROS_H_TARGET    syscall_macros_h_target)
set(SYSCALL_LIST_H_TARGET      syscall_list_h_target)
set(DRIVER_VALIDATION_H_TARGET driver_validation_h_target)
set(KOBJ_TYPES_H_TARGET        kobj_types_h_target)
set(LINKER_SCRIPT_TARGET       linker_script_target)

add_library(embarc_osp_interface INTERFACE)

##########embarc_osp_library_named(embarc_osp)

## include path
embarc_osp_include_directories(
  arc
  board
  include
  inc
  inc/arc
)
###compile_definitions

## toolchain
add_subdirectory(${EMBARC_OSP}/library)
add_subdirectory(${EMBARC_OSP}/inc)
add_subdirectory(${EMBARC_OSP}/board)
add_subdirectory(${EMBARC_OSP}/device)
add_subdirectory(${EMBARC_OSP}/arc)

