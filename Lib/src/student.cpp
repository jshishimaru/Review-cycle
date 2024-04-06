#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/include/student.hpp"

// student::student(){};
// student::~student(){};
// student::student( const student &student){
     
//     this->statuses = student.statuses;
//     this->tasks = student.tasks;

// }


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
