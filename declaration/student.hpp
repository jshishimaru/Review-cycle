#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <assignment.hpp>
#include <img_member.hpp>
#include <map>
#include <vector>
using namespace std;

class student{
       
      public:
      void get_status( assignemt assignemt);
      void set_status( assignemt assignemt , status status);
      void get_all_status();
      void get_tasks( assignemt assignemt);
      void get_all_tasks();
      void set_task ( assignemt assignemt , task task);

       private:
       map <assignemt , status > status;
       map <assignemt , vector <task> > tasks;


};

#endif