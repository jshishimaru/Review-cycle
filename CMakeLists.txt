# cmake_minimum_required(VERSION 3.0.0)
# project( Review-Cycle VERSION 0.1.0 LANGUAGES C CXX)


# add_subdirectory(Lib)
# add_subdirectory(App)

cmake_minimum_required(VERSION 3.10)
project(App)
add_executable(App main.cpp)


add_subdirectory(./Lib Lib)
target_link_libraries(App PUBLIC Lib)
target_include_directories(App PUBLIC "./build" "../Lib")