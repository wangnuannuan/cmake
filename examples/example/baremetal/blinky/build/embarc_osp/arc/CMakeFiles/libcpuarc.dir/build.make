# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/wang/anaconda3/lib/python3.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/wang/anaconda3/lib/python3.7/site-packages/cmake/data/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wang/Documents/PythonLearn/example/baremetal/blinky

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wang/Documents/PythonLearn/example/baremetal/blinky/build

# Include any dependencies generated for this target.
include embarc_osp/arc/CMakeFiles/libcpuarc.dir/depend.make

# Include the progress variables for this target.
include embarc_osp/arc/CMakeFiles/libcpuarc.dir/progress.make

# Include the compile flags for this target's objects.
include embarc_osp/arc/CMakeFiles/libcpuarc.dir/flags.make

embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o: embarc_osp/arc/CMakeFiles/libcpuarc.dir/flags.make
embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o: ../../../../arc/arc_exc_asm.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/Documents/PythonLearn/example/baremetal/blinky/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o"
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o -c /home/wang/Documents/PythonLearn/arc/arc_exc_asm.s

embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_util.s.o: embarc_osp/arc/CMakeFiles/libcpuarc.dir/flags.make
embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_util.s.o: ../../../../arc/arc_util.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/Documents/PythonLearn/example/baremetal/blinky/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_util.s.o"
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/libcpuarc.dir/arc_util.s.o -c /home/wang/Documents/PythonLearn/arc/arc_util.s

# Object files for target libcpuarc
libcpuarc_OBJECTS = \
"CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o" \
"CMakeFiles/libcpuarc.dir/arc_util.s.o"

# External object files for target libcpuarc
libcpuarc_EXTERNAL_OBJECTS =

embarc_osp/arc/liblibcpuarc.a: embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_exc_asm.s.o
embarc_osp/arc/liblibcpuarc.a: embarc_osp/arc/CMakeFiles/libcpuarc.dir/arc_util.s.o
embarc_osp/arc/liblibcpuarc.a: embarc_osp/arc/CMakeFiles/libcpuarc.dir/build.make
embarc_osp/arc/liblibcpuarc.a: embarc_osp/arc/CMakeFiles/libcpuarc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wang/Documents/PythonLearn/example/baremetal/blinky/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking ASM static library liblibcpuarc.a"
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc && $(CMAKE_COMMAND) -P CMakeFiles/libcpuarc.dir/cmake_clean_target.cmake
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcpuarc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
embarc_osp/arc/CMakeFiles/libcpuarc.dir/build: embarc_osp/arc/liblibcpuarc.a

.PHONY : embarc_osp/arc/CMakeFiles/libcpuarc.dir/build

embarc_osp/arc/CMakeFiles/libcpuarc.dir/clean:
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc && $(CMAKE_COMMAND) -P CMakeFiles/libcpuarc.dir/cmake_clean.cmake
.PHONY : embarc_osp/arc/CMakeFiles/libcpuarc.dir/clean

embarc_osp/arc/CMakeFiles/libcpuarc.dir/depend:
	cd /home/wang/Documents/PythonLearn/example/baremetal/blinky/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wang/Documents/PythonLearn/example/baremetal/blinky /home/wang/Documents/PythonLearn/arc /home/wang/Documents/PythonLearn/example/baremetal/blinky/build /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc /home/wang/Documents/PythonLearn/example/baremetal/blinky/build/embarc_osp/arc/CMakeFiles/libcpuarc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : embarc_osp/arc/CMakeFiles/libcpuarc.dir/depend

