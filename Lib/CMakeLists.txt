add_library(Lib src/img_member.cpp src/reviewer.cpp src/student.cpp src/)
 
target_include_directories( Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)