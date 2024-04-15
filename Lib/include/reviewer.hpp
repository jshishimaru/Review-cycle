#ifndef REVIEWER_HPP
#define REVIEWER_HPP

#include <iostream>
#include "student.hpp"


class reviewer : public img_member{


    public:

    // reviewer();
    // ~reviewer();
    // reviewer(const reviewer &reviewer);

    void view_status( assignment assignment , vector <student> students);
    void change_status(assignment assignment , vector <student> students);
    void add_task( assignment assignment , student &student , string task);
    void change_task ( student &student , int tasknumber , int flag);
    int add_assignment( vector <student> &students);
    void view_assignments();
    

};


int set_member( string id , string password , int flag , vector <student> &students , vector <reviewer> &reviewers );
int reviewer_login( string id , string password , reviewer &cur_reviewer , vector <reviewer> &reviewers);


#endif