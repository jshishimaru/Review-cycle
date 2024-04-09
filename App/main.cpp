#include <iostream>
#include <fstream>
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/student.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/img_member.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/reviewer.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/assignment.cpp"

using namespace std;

vector <student> students;
vector <reviewer> reviewers;

student cur_student;
reviewer cur_reviewer;



void project(){
    
    set_member( "1" , "1" , 0 , students , reviewers  );
    set_member( "2" , "2" , 1 , students , reviewers  );
   //WELCOME 
  
   cout << "\t\tWELCOME TO REVIEW-CYCLE!" << endl;

   cout << endl << endl << endl;
     
   cout << "press 1 to restart" << endl;
   cout << "press 2 to login as student" << endl;
   cout << "press 3 to login as reviewer"<< endl;
   cout << "press 4 to create new profile" << endl;
   cout << "press 5 to exit" << endl;

   Log logged_in_as = NOONE;
   int input;
   cin>>input;

   string cur_id;
   string cur_password;
    

   // login part 

   switch(input){

   case 2:

   cout << "Enter Your ID!" << endl;
   cin>>cur_id;
   cout << "Enter Your Password"<<endl;
   cin>>cur_password;

   switch(student_login(cur_id , cur_password , cur_student , students)){
     case 0:   
     cout << "WRONG ID!" << endl;
     break;
     case 1: 
     cout << "Logged in Successfully" << endl;
     logged_in_as = STUDENT;
     break;
     case 2:
     cout << "WRONG PASSWORD!" << endl;
     break;
   } 
     
   break;

   case 3:
   cout << "Enter Your ID!" << endl;
   cin>>cur_id;
   cout << "Enter Your Password"<<endl;
   cin>>cur_password;

   switch(reviewer_login(cur_id , cur_password , cur_reviewer , reviewers)){
     case 0:   
     cout << "WRONG ID!" << endl;
     break;
     case 1: 
     cout << "Logged in Successfully" << endl;
     logged_in_as = REVIEWER;
     break;
     case 2:
     cout << "WRONG PASSWORD!" << endl;
     break;
   } 

   break;


   case 4:


   cout << "press 1 to create new reviewer"<<endl;
   cout << "press 2 to create new student"<<endl;
   
   int input2;
   cin>>input2;

   cout << "Enter New ID" << endl;
   cin>>cur_id;
   cout << "Create your password" << endl;
   cin>>cur_password;

   if(set_member( cur_id , cur_password , input2-1 , students , reviewers  )){
   
       cout << "ERROR! user already exists" << endl;
     
   }
   else{
        cout << "New user created!" << endl;
   }
   
   break;
   } 

   cout << endl << endl;

   if( logged_in_as == REVIEWER){
      
     cout << "WELCOME! " << cur_reviewer.getid() << endl;
     

     int in = 0;
     while( in!=5){

           cout << "press 1 to view current assignments"<<endl;
           cout << "press 2 to add a new assignment" << endl;
           cout << "press 5 to go back" << endl;
             
           cin>>in;
           switch(in){
   
              case 1:
              cur_reviewer.view_assignments();
              cout << "press 1 to select assignment" << endl;

              int in3;
              cin>>in3;
              
              
              switch( in3 ){
                  
                  case 1:
                  cout << "Enter Assignment No. : ";
                  int num;
                  cin>>num;
                  assignment cur_ass = get_assignment(num);
                  cout << cur_ass.getnumber() << " " << cur_ass.getname() << " : " << endl;
                  cout << "Desciption : " <<  cur_ass.getdescription();

                  cout << "press 1 to view student status" << endl;

                  int in2;
                  cin>>in2;
                  if( in2 == 1){
                        
                        cout << endl << "List of students : " << endl;

                        cur_reviewer.view_status( cur_ass , students);

                        cout << "press 1 to select student" << endl;
                        int in4;
                        cin>>in4;

                        if( in4 == 1 ){

                            cout << "Enter student ID. : " << endl;
                            string stu;
                            cin>>stu;
                            
                            student *temp = NULL;
                            temp = get_student( stu , students );
                            if( temp == NULL){
                                 
                                  cout << "No ID found!" << endl;

                            }
                            else{
                                
                                cout << "Assignment selected : " << cur_ass.getname() << endl;
                                cout << "Student Selected : "<< temp->getid() << endl << endl;
                                cout << "press 1 to view tasks" << endl;
                                cout << "press 2 to change task status" << endl;
                                cout << "press 3 to add new tasks" << endl;
                                cout << "press 4 to change assignment status" << endl;

                                int in5;
                                string task_name;
                                cin>>in5;

                                switch(in5){
 
                                      case 1:
                                      temp->get_tasks( cur_ass );
                                      break;
                                      case 2:
                                      cout << "Enter Task No. : ";
                                      int tasknum;
                                      cin>>tasknum;
                                      cout << "Press 1 to set as Pending" << endl;
                                      cout << "Press 2 to set as Complete" << endl;
                                      int stat;
                                      cin>>stat;
                                      if( temp->change_task_status(cur_ass , stat , tasknum)){
                                            cout << "Changed Successfully!" << endl;
                                      }
                                      else{
                                          cout << "No task found!" << endl;
                                      }
                                      break;
                                      case 3:
                                      cout << "Enter Your Task : " << endl;
                                      cin>>task_name;

                                      temp->add_task( cur_ass , task_name );
                                      break;

                                      case 4:
                                      cout << "Press 0 for Pending , 1 for In iteration , 2 for completed" << endl;
                                      int flag;
                                      cin>>flag;
                                      temp->change_assignment_status( cur_ass , flag );
                                      break;


                                }

                            }

                        }

                  }
                  
                  break;
              }
              break;

              case 2:
              cur_reviewer.add_assignment( students);
              break;

              case 5:
              logged_in_as = NOONE;
              break;

           }
            
     }
     


   }
    
    else if ( logged_in_as == STUDENT){

           int in;
           
           while( in!=5){

           cout<< "press 1 to see your assignments" << endl;
           cout <<"press 2 to see your tasks" << endl;
           cout<< "press 5 to exit" << endl;

              cin>>in;

              switch(in){
  
                case 1:
                cur_student.see_all_status();
                break;

                case 2:
                cur_student.get_all_tasks();
                break;

              }

           }

    }

   cout << endl << endl << endl;
   if(logged_in_as == NOONE)project();


}

int main(){

     project();

     return 0;
}