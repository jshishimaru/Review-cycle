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

    assignment();

    int set_assignment( string name , string description , date deadline1 , date deadline2);
    string getname();
    const int getnumber() const;

    private:
    string name;
    string description;
    int number;
    static int total_assignments;
    date iteration_deadline;
    date final_deadline;


};

int assignment::total_assignments=0;


#endif