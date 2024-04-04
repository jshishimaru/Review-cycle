#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <string>
using namespace std;

struct date{
  
    int date;
    int month;
    int year;

    void setdate( int date , int month , int year );
    void setdate( int date , int month );
    void getdate();

};

class task{
 
     public:
     string name;
     bool completed;

     void set_task( string name , bool completed);
     void get_task();

};

class assignemt{
    
    private:
    string name;
    string description;
    int number;
    date deadline;



};



#endif