cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)

project(gameOfLife LANGUAGES C)

if(SDL) 
	add_subdirectory(game_sdl)
	set (SRC main_sdl.c)
	add_executable(${PROJECT_NAME} "")
	target_sources(${PROJECT_NAME} PUBLIC ${SRC})
	target_link_libraries(${PROJECT_NAME} PUBLIC game_sdl) 
	find_package(SDL2 REQUIRED)
	include_directories(${SDL2_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PUBLIC game_sdl ${SDL2_LIBRARIES})

	set(TEST_PROJECT1 test_pract1)
	add_executable(${TEST_PROJECT1})
	target_sources(${TEST_PROJECT1} PUBLIC ctest.c)
	target_link_libraries({TEST_PROJECT1} PUBLIC game_sdl ${SDL2_LIBRARIES} cunit)
	

	install(TARGETS ${PROJECT_NAME})
else() 
	add_subdirectory(game)	
	add_subdirectory(console)
	set (SRC main.c)
	add_executable(${PROJECT_NAME} "")
	target_sources(${PROJECT_NAME} PUBLIC ${SRC})
	target_link_libraries(${PROJECT_NAME} PUBLIC game) 
	target_link_libraries(${PROJECT_NAME} PUBLIC console) 

	set(TEST_PROJECT1 test_pract1)
	add_executable(${TEST_PROJECT1})
	target_sources(${TEST_PROJECT1} PUBLIC ctest.c)
	target_link_libraries({TEST_PROJECT1} PUBLIC game cunit )

	install(TARGETS ${PROJECT_NAME})
endif()


