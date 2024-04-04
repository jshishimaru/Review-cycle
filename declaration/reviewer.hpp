#ifndef REVIEWER_HPP
#define REVIEWER_HPP

#include <img_member.hpp>
#include <student.hpp>
#include <assignment.hpp>

class reviewer : public img_member{


    public:


    void view_status( assignemt assignemt);
    void change_status( assignemt assignemt , student &student , int flag);
    void add_task( assignemt assignemt , student &student , string task);
    void change_task ( student &student , int tasknumber , int flag);
    void add_assignment( string name , string description , date deadline);
    

};



#endif