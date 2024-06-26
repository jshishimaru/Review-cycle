#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "assignment.hpp"
#include "img_member.hpp"
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class assignment_cmp{
  
   public:
   bool operator()(const assignment &a , const assignment &b)const;

};

class student : public img_member{
       
      public:

      // student();
      // ~student();
      // student( const student &student);

      status get_status( assignment assignment);
      void set_status( assignment assignment , status status);
      void see_all_status();
      void get_tasks( assignment assignment);
      void get_all_tasks();
      int get_task_count( assignment assignment);
      void add_task ( assignment assignment , string task);
      void add_task( assignment assignment , task task);
      int change_task_status( assignment assignment , int stat , int tasknumber);
      void change_assignment_status( assignment assignment , int flag);
      vector <task> get_task_vector( assignment assignment);
      void set_link ( assignment assignemt , string link);
      void set_submission( int assignment_num , string link , vector <student> &students);
      void get_link( assignment ass);
      string get_link( assignment ass ,int flag);


       private:
       map <assignment , status , assignment_cmp> statuses;
       map <assignment , vector <task> , assignment_cmp> tasks;
       map <assignment , string , assignment_cmp> submissions;


};
student* get_student( string id , vector <student> &students);
int student_login( string id , string password , student &cur_student , vector <student> &students);




#endif