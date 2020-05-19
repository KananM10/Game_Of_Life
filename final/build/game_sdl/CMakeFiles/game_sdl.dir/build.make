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
include game_sdl/CMakeFiles/game_sdl.dir/depend.make

# Include the progress variables for this target.
include game_sdl/CMakeFiles/game_sdl.dir/progress.make

# Include the compile flags for this target's objects.
include game_sdl/CMakeFiles/game_sdl.dir/flags.make

game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.o: game_sdl/CMakeFiles/game_sdl.dir/flags.make
game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.o: ../game_sdl/game_sdl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.o"
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game_sdl.dir/game_sdl.c.o   -c /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/game_sdl/game_sdl.c

game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game_sdl.dir/game_sdl.c.i"
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/game_sdl/game_sdl.c > CMakeFiles/game_sdl.dir/game_sdl.c.i

game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game_sdl.dir/game_sdl.c.s"
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/game_sdl/game_sdl.c -o CMakeFiles/game_sdl.dir/game_sdl.c.s

# Object files for target game_sdl
game_sdl_OBJECTS = \
"CMakeFiles/game_sdl.dir/game_sdl.c.o"

# External object files for target game_sdl
game_sdl_EXTERNAL_OBJECTS =

game_sdl/libgame_sdl.a: game_sdl/CMakeFiles/game_sdl.dir/game_sdl.c.o
game_sdl/libgame_sdl.a: game_sdl/CMakeFiles/game_sdl.dir/build.make
game_sdl/libgame_sdl.a: game_sdl/CMakeFiles/game_sdl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libgame_sdl.a"
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && $(CMAKE_COMMAND) -P CMakeFiles/game_sdl.dir/cmake_clean_target.cmake
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_sdl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
game_sdl/CMakeFiles/game_sdl.dir/build: game_sdl/libgame_sdl.a

.PHONY : game_sdl/CMakeFiles/game_sdl.dir/build

game_sdl/CMakeFiles/game_sdl.dir/clean:
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl && $(CMAKE_COMMAND) -P CMakeFiles/game_sdl.dir/cmake_clean.cmake
.PHONY : game_sdl/CMakeFiles/game_sdl.dir/clean

game_sdl/CMakeFiles/game_sdl.dir/depend:
	cd /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/game_sdl /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final/build/game_sdl/CMakeFiles/game_sdl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : game_sdl/CMakeFiles/game_sdl.dir/depend

