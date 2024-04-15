add_library(Lib src/img_member.cpp src/reviewer.cpp src/student.cpp src/assignment.cpp  ./include/img_member.hpp
            ./include/reviewer.hpp ./include/student.hpp ./include/assignment.hpp)
 
# target_include_directories( Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)