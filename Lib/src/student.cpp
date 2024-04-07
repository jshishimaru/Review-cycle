#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/include/student.hpp"

#include <iostream>
using namespace std;
// student::student(){};
// student::~student(){};
// student::student( const student &student){
     
//     this->statuses = student.statuses;
//     this->tasks = student.tasks;

// }

bool assignment_cmp::operator()(const assignment &a , const assignment &b)const{
    
      return a.getnumber() < b.getnumber();

}



int student_login( string id , string password , student &cur_student , vector <student> &students){
    
     for( auto val : students){
  
       if( id == val.getid()){

               if( val.check_member(id,password) ){
                  
                   cur_student = val;
                   return 1;

               }
               else{
                    
                    return 2;
                    
               }

       }
     }

     return 0;

    // return 0 means no id found
    // return 1 means logged in successfully
    // return 2 means wrong password for the id


}

status student::get_status( assignment assignment){
       
    return this->statuses[assignment];

}

void student::see_all_status(){


   for( auto &val : this->statuses){

         assignment temp = val.first;

         cout << temp.getnumber() << ". " << temp.getname() << " - "; 
         
         switch( val.second ){
           
           case PENDING:
           cout << "Pending" << endl;
           break;
           case IN_ITERATION:
           cout << "In Iteration" << endl;
           break;
           case  COMPLETED:
           cout << "Completed" << endl;
           break;


         }


   }
  


}

void student::set_status( assignment assignment , status status){

       this->statuses[assignment] = status;

}
