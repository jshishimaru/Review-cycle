#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "assignment.hpp"
#include "img_member.hpp"
#include <map>
#include <vector>
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
      void set_task ( assignment assignment , task task);


       private:
       map <assignment , status , assignment_cmp> statuses;
       map <assignment , vector <task> , assignment_cmp> tasks;


};

int student_login( string id , string password , student &cur_student , vector <student> &students);



#endif