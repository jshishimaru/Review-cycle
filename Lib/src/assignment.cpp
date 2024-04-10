// #include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/include/assignment.hpp"
#include "../include/assignment.hpp"
#include <iostream>

using namespace std;

assignment::assignment(){
     this->number = total_assignments + 1;
     this->total_assignments++;
}
string assignment::getname(){
     return this->name;
}

date::date(){};
date::date(string a){

     string temp = a.substr(0,2);
     this->day = stoi(temp);
     temp = a.substr(3,5);
     this->month = stoi(temp);
     temp = a.substr( 6,10 );
     this->year = stoi(temp);

}


int assignment::set_assignment( string name , string description , date deadline1, date deadline2){
    
     this->name = name;
     this->description = description;
     this->iteration_deadline = deadline1;
     this->final_deadline = deadline2;

     return 0;

}

void date::setdate( int date , int month , int year){
   
     this->day = date;
     this->month = month;
     this->year = year; 
  
}

void date::setdate(string date){
    
     string temp = date.substr(0,2);
     this->day = stoi(temp);
     temp = date.substr(3,5);
     this->month = stoi(temp);
     temp = date.substr( 6,10 );
     this->year = stoi(temp);

}

const int assignment::getnumber()const{
     return number;
}

string assignment::getdescription(){

    return this->description;

}

task::task( string name){
      this-> name = name;
      completed = false;
}

task::task(string name , bool completed){
 
   this->name = name;
   this->completed = completed;

}