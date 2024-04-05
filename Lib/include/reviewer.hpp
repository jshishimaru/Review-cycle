#ifndef REVIEWER_HPP
#define REVIEWER_HPP

#include "img_member.hpp"
#include "student.hpp"
#include "assignment.hpp"

class reviewer : public img_member{


    public:


    void view_status( assignment assignment);
    void change_status( assignment assignment , student &student , int flag);
    void add_task( assignment assignment , student &student , string task);
    void change_task ( student &student , int tasknumber , int flag);
    void add_assignment( string name , string description , date deadline);
    

};



#endif