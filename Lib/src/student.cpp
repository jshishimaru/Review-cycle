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

student* get_student( string id , vector <student> &students){

       for( auto &val : students){
             
             if( id == val.getid() ){

                return &val;

             }

       }
       return NULL;

}

void student::get_tasks( assignment ass){
 
      for( auto &val : tasks){

             assignment tmp = val.first;

             if( ass.getname() == tmp.getname()){
                             
                      vector <task> &tasks = val.second;
                      int index = 1;
                      for( auto &task : tasks){

                              cout << index << ". "<<task.name << " : ";
                              if( task.completed){

                                    cout << "Completed" << endl;      

                              }
                              else cout << "Pending" << endl;

                              index++;

                      }
             }

      }

}

int student::change_task_status( assignment ass , int stat , int tasknumber){

      for( auto &val : this->tasks){

             assignment temp = val.first;

             if( ass.getname() == temp.getname() ){

                   vector <task> &t = val.second;

                   int index = 1;

                   for( auto &tas : t ){

                        if( index == tasknumber){
                          
                            tas.completed = stat - 1;
                            return 1;

                        }      

                   }

             }

      }
      return 0;
}

void student::add_task( assignment ass , string tsk){
  
           vector <task> &t = this->tasks[ass];
           t.push_back( (tsk) );

}

void student::change_assignment_status( assignment ass , int flag){
  
            if( flag == 0){
                   this->statuses[ass] = PENDING;
            }
            if( flag == 1){
                   this->statuses[ass] = IN_ITERATION;
            }
            if( flag == 2){
                   this->statuses[ass] = COMPLETED;
            }
}

void student::get_all_tasks(){

     for( auto &val : this->tasks){

           assignment tmp = val.first;
           for( auto task : val.second){

                  cout << tmp.getnumber() << ". " << tmp.getname() << " - "<<task.name<<endl;

           }

     }

}

void student::add_task( assignment assignment , task task){
  
         this->tasks[assignment].push_back(task);

}

int student::get_task_count( assignment assignment ){
  
     return this->tasks[assignment].size();

}

vector <task> student::get_task_vector( assignment assignment){
 
     return this->tasks[assignment];

}
