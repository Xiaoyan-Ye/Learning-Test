# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\mwang9\Downloads\Tool\cmake-3.15.3-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\mwang9\Downloads\Tool\cmake-3.15.3-win64-x64\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\mwang9\Downloads\Workspace\test\cmake project test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mwang9\Downloads\Workspace\test\cmake project test"

# Include any dependencies generated for this target.
include CMakeFiles/Test1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test1.dir/flags.make

CMakeFiles/Test1.dir/test1.c.obj: CMakeFiles/Test1.dir/flags.make
CMakeFiles/Test1.dir/test1.c.obj: CMakeFiles/Test1.dir/includes_C.rsp
CMakeFiles/Test1.dir/test1.c.obj: test1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mwang9\Downloads\Workspace\test\cmake project test\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Test1.dir/test1.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Test1.dir\test1.c.obj   -c "C:\Users\mwang9\Downloads\Workspace\test\cmake project test\test1.c"

CMakeFiles/Test1.dir/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test1.dir/test1.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\mwang9\Downloads\Workspace\test\cmake project test\test1.c" > CMakeFiles\Test1.dir\test1.c.i

CMakeFiles/Test1.dir/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test1.dir/test1.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\mwang9\Downloads\Workspace\test\cmake project test\test1.c" -o CMakeFiles\Test1.dir\test1.c.s

# Object files for target Test1
Test1_OBJECTS = \
"CMakeFiles/Test1.dir/test1.c.obj"

# External object files for target Test1
Test1_EXTERNAL_OBJECTS =

Test1.exe: CMakeFiles/Test1.dir/test1.c.obj
Test1.exe: CMakeFiles/Test1.dir/build.make
Test1.exe: CMakeFiles/Test1.dir/linklibs.rsp
Test1.exe: CMakeFiles/Test1.dir/objects1.rsp
Test1.exe: CMakeFiles/Test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mwang9\Downloads\Workspace\test\cmake project test\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test1.dir/build: Test1.exe

.PHONY : CMakeFiles/Test1.dir/build

CMakeFiles/Test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test1.dir/clean

CMakeFiles/Test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mwang9\Downloads\Workspace\test\cmake project test" "C:\Users\mwang9\Downloads\Workspace\test\cmake project test" "C:\Users\mwang9\Downloads\Workspace\test\cmake project test" "C:\Users\mwang9\Downloads\Workspace\test\cmake project test" "C:\Users\mwang9\Downloads\Workspace\test\cmake project test\CMakeFiles\Test1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Test1.dir/depend

