#ifndef REVIEWER_HPP
#define REVIEWER_HPP

#include "student.hpp"


class reviewer : public img_member{


    public:

    // reviewer();
    // ~reviewer();
    // reviewer(const reviewer &reviewer);

    void view_status( assignment assignment);
    void change_status( assignment assignment , student &student , int flag);
    void add_task( assignment assignment , student &student , string task);
    void change_task ( student &student , int tasknumber , int flag);
    int add_assignment();
    

};


int set_member( string id , string password , int flag , vector <student> &students , vector <reviewer> &reviewers );
int reviewer_login( string id , string password , reviewer &cur_reviewer , set <reviewer> &reviewers);


#endif