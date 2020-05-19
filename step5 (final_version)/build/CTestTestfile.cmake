# CMake generated Testfile for 
# Source directory: /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final_version/CMakeList
# Build directory: /home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final_version/CMakeList/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyCunitTest "/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final_version/CMakeList/build/test_pract1")
set_tests_properties(MyCunitTest PROPERTIES  _BACKTRACE_TRIPLES "/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final_version/CMakeList/CMakeLists.txt;37;add_test;/home/kanan/Desktop/L2_S2_2019/Development_Techniques/Game_Of_Life/final_version/CMakeList/CMakeLists.txt;0;")
subdirs("game_sdl")
subdirs("game")
subdirs("console")
