#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "assignment.hpp"
#include "img_member.hpp"
#include <map>
#include <vector>
using namespace std;

class student{
       
      public:
      void get_status( assignment assignment);
      void set_status( assignment assignment , status status);
      void get_all_status();
      void get_tasks( assignment assignment);
      void get_all_tasks();
      void set_task ( assignment assignment , task task);

       private:
       map <assignment , status > statuses;
       map <assignment , vector <task> > tasks;


};

#endif