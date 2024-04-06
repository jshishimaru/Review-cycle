#include <iostream>
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
     
     cout << "press 1 to view current assignments"<<endl;
     cout << "press 2 to add a new assignment" << endl;
     


   }

   






   cout << endl << endl << endl;
   project();


}

int main(){

     project();

     return 0;
}