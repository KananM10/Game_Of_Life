# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build

# Include any dependencies generated for this target.
include CMakeFiles/gameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameOfLife.dir/flags.make

CMakeFiles/gameOfLife.dir/main.c.o: CMakeFiles/gameOfLife.dir/flags.make
CMakeFiles/gameOfLife.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gameOfLife.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gameOfLife.dir/main.c.o   -c /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/main.c

CMakeFiles/gameOfLife.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gameOfLife.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/main.c > CMakeFiles/gameOfLife.dir/main.c.i

CMakeFiles/gameOfLife.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gameOfLife.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/main.c -o CMakeFiles/gameOfLife.dir/main.c.s

# Object files for target gameOfLife
gameOfLife_OBJECTS = \
"CMakeFiles/gameOfLife.dir/main.c.o"

# External object files for target gameOfLife
gameOfLife_EXTERNAL_OBJECTS =

gameOfLife: CMakeFiles/gameOfLife.dir/main.c.o
gameOfLife: CMakeFiles/gameOfLife.dir/build.make
gameOfLife: game/libgame.a
gameOfLife: console/libconsole.a
gameOfLife: CMakeFiles/gameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gameOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameOfLife.dir/build: gameOfLife

.PHONY : CMakeFiles/gameOfLife.dir/build

CMakeFiles/gameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameOfLife.dir/clean

CMakeFiles/gameOfLife.dir/depend:
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/CMakeFiles/gameOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameOfLife.dir/depend

