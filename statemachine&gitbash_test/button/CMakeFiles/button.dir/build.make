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
CMAKE_SOURCE_DIR = C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2

# Include any dependencies generated for this target.
include button/CMakeFiles/button.dir/depend.make

# Include the progress variables for this target.
include button/CMakeFiles/button.dir/progress.make

# Include the compile flags for this target's objects.
include button/CMakeFiles/button.dir/flags.make

button/CMakeFiles/button.dir/button.c.obj: button/CMakeFiles/button.dir/flags.make
button/CMakeFiles/button.dir/button.c.obj: button/button.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object button/CMakeFiles/button.dir/button.c.obj"
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\button.dir\button.c.obj   -c C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button\button.c

button/CMakeFiles/button.dir/button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/button.dir/button.c.i"
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button\button.c > CMakeFiles\button.dir\button.c.i

button/CMakeFiles/button.dir/button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/button.dir/button.c.s"
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button\button.c -o CMakeFiles\button.dir\button.c.s

# Object files for target button
button_OBJECTS = \
"CMakeFiles/button.dir/button.c.obj"

# External object files for target button
button_EXTERNAL_OBJECTS =

button/libbutton.a: button/CMakeFiles/button.dir/button.c.obj
button/libbutton.a: button/CMakeFiles/button.dir/build.make
button/libbutton.a: button/CMakeFiles/button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbutton.a"
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && $(CMAKE_COMMAND) -P CMakeFiles\button.dir\cmake_clean_target.cmake
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\button.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
button/CMakeFiles/button.dir/build: button/libbutton.a

.PHONY : button/CMakeFiles/button.dir/build

button/CMakeFiles/button.dir/clean:
	cd /d C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button && $(CMAKE_COMMAND) -P CMakeFiles\button.dir\cmake_clean.cmake
.PHONY : button/CMakeFiles/button.dir/clean

button/CMakeFiles/button.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2 C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2 C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button C:\Users\mwang9\Downloads\Documents\ITC_OJT\statemachine\statemachine_V2\button\CMakeFiles\button.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : button/CMakeFiles/button.dir/depend
