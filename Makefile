# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tuto/code/rk1808/cgz_folder/xmodem-linux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tuto/code/rk1808/cgz_folder/xmodem-linux

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tuto/code/rk1808/cgz_folder/xmodem-linux/CMakeFiles /home/tuto/code/rk1808/cgz_folder/xmodem-linux/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tuto/code/rk1808/cgz_folder/xmodem-linux/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named xmodem

# Build rule for target.
xmodem: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 xmodem
.PHONY : xmodem

# fast build rule for target.
xmodem/fast:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/build
.PHONY : xmodem/fast

crc16.o: crc16.cpp.o

.PHONY : crc16.o

# target to build an object file
crc16.cpp.o:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/crc16.cpp.o
.PHONY : crc16.cpp.o

crc16.i: crc16.cpp.i

.PHONY : crc16.i

# target to preprocess a source file
crc16.cpp.i:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/crc16.cpp.i
.PHONY : crc16.cpp.i

crc16.s: crc16.cpp.s

.PHONY : crc16.s

# target to generate assembly for a file
crc16.cpp.s:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/crc16.cpp.s
.PHONY : crc16.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/main.cpp.s
.PHONY : main.cpp.s

usart.o: usart.cpp.o

.PHONY : usart.o

# target to build an object file
usart.cpp.o:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/usart.cpp.o
.PHONY : usart.cpp.o

usart.i: usart.cpp.i

.PHONY : usart.i

# target to preprocess a source file
usart.cpp.i:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/usart.cpp.i
.PHONY : usart.cpp.i

usart.s: usart.cpp.s

.PHONY : usart.s

# target to generate assembly for a file
usart.cpp.s:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/usart.cpp.s
.PHONY : usart.cpp.s

xmodem.o: xmodem.cpp.o

.PHONY : xmodem.o

# target to build an object file
xmodem.cpp.o:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem.cpp.o
.PHONY : xmodem.cpp.o

xmodem.i: xmodem.cpp.i

.PHONY : xmodem.i

# target to preprocess a source file
xmodem.cpp.i:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem.cpp.i
.PHONY : xmodem.cpp.i

xmodem.s: xmodem.cpp.s

.PHONY : xmodem.s

# target to generate assembly for a file
xmodem.cpp.s:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem.cpp.s
.PHONY : xmodem.cpp.s

xmodem_linux.o: xmodem_linux.cpp.o

.PHONY : xmodem_linux.o

# target to build an object file
xmodem_linux.cpp.o:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem_linux.cpp.o
.PHONY : xmodem_linux.cpp.o

xmodem_linux.i: xmodem_linux.cpp.i

.PHONY : xmodem_linux.i

# target to preprocess a source file
xmodem_linux.cpp.i:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem_linux.cpp.i
.PHONY : xmodem_linux.cpp.i

xmodem_linux.s: xmodem_linux.cpp.s

.PHONY : xmodem_linux.s

# target to generate assembly for a file
xmodem_linux.cpp.s:
	$(MAKE) -f CMakeFiles/xmodem.dir/build.make CMakeFiles/xmodem.dir/xmodem_linux.cpp.s
.PHONY : xmodem_linux.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... xmodem"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... edit_cache"
	@echo "... crc16.o"
	@echo "... crc16.i"
	@echo "... crc16.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... usart.o"
	@echo "... usart.i"
	@echo "... usart.s"
	@echo "... xmodem.o"
	@echo "... xmodem.i"
	@echo "... xmodem.s"
	@echo "... xmodem_linux.o"
	@echo "... xmodem_linux.i"
	@echo "... xmodem_linux.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
