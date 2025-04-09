cmake_minimum_required(VERSION 3.15)

project(SnakeGame)

# set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find sdl libraries
find_package(SDL REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)

# include directories
include_directories( ${SDL_INCLUDE_DIR} ${SDL_MIXER_INCLUDE_DIR} ${SDL_TTF_INCLUDE_DIR})

# sources files
set(SOURCES main.cpp snake.cpp node.cpp)

# add executable
add_executable(snake ${SOURCES})

# link sdl libraries
target_link_libraries(snake ${SDL_LIBRARY} ${SDL_MIXER_LIBRARY} ${SDL_TTF_LIBRARY})

# install
install(TARGETS snake
RUNTIME DESTINATION bin
)

install(DIRECTORY assets/
DESTINATION bin/assets
)
