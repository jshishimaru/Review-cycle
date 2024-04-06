#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <string>
using namespace std;

class date{

    public :

    int date;
    int month;
    int year;

    void setdate( int date , int month , int year );
    void setdate( string date);
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



class assignment{

    public:


    int set_assignment( string name , string description , date deadline1 , date deadline2);
    string getname();
    
    private:
    string name;
    string description;
    int number;
    date iteration_deadline;
    date final_deadline;


};



#endif