cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)

project(gameOfLife LANGUAGES C)

if(SDL) 
	add_subdirectory(game_sdl)
	set (SRC main_sdl.c)
else() 
	add_subdirectory(game)	
	add_subdirectory(console)
	set (SRC main.c)
endif()


add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})


if(SDL)
	target_link_libraries(${PROJECT_NAME} PUBLIC game_sdl) 
	find_package(SDL2 REQUIRED)
	include_directories(${SDL2_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PUBLIC game_sdl ${SDL2_LIBRARIES})
else()
	target_link_libraries(${PROJECT_NAME} PUBLIC game) 
	target_link_libraries(${PROJECT_NAME} PUBLIC console) 
endif()

install(TARGETS ${PROJECT_NAME})
