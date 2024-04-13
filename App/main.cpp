#include <iostream>
#include <fstream>
#include <sstream>
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/student.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/img_member.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/reviewer.cpp"
#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/src/assignment.cpp"
using namespace std;

vector <student> students;
vector <reviewer> reviewers;

student cur_student;
reviewer cur_reviewer;

void get_input(){

      vector <string> ass;
   
      ifstream in;
      in.open("data/assignments.txt");

      string temp;
      
      while( getline(in ,temp) ){

              ass.push_back(temp);

      }
      int index = 0;

      int number_of_ass = ass.size()/4;

      while( number_of_ass-- ){


          assignment temp_ass;
          temp_ass.set_assignment( ass[index] ,ass[index+1] , ass[index+2] , ass[index+3] );
          assignments.push_back(temp_ass);
          index+=4;

      }

      in.close();
      
        
      in.open("data/reviewers.txt");
      ass.clear();

      while( getline( in , temp)){

            ass.push_back(temp);

      }

      index = 0;
      number_of_ass = ass.size()/2;

      while( number_of_ass--){

            reviewer temp_rev;
            stringstream ss;
            ss << ass[index+1];
            size_t temp;
            ss >> temp;

            temp_rev.set_existing_profile(ass[index] , temp , 1);

            reviewers.push_back(temp_rev);
            index+=2;

      }

      in.close();

      in.open( "data/students.txt");


      number_of_ass = assignments.size();
      while(getline(in,temp)){
        
         string name = temp;
         string password;
         getline( in , password);

         student temp_stu;
         stringstream ss;
         ss<<password;
         size_t temp;
         ss>>temp;
         temp_stu.set_existing_profile(name,temp,0);

         for( auto &val : assignments){

             string task_number;
             int number_of_task;

             string assignment_status;
             getline( in , assignment_status);

             string repo_link;
             getline(in, repo_link);
             temp_stu.set_link( val , repo_link);

             if( assignment_status == "pending"){
  
                  temp_stu.change_assignment_status( val , PENDING);

             }
             else if ( assignment_status == "in_iteration"){
                  temp_stu.change_assignment_status( val , IN_ITERATION);
             }
             else{
                  temp_stu.change_assignment_status( val , COMPLETED);
             }

             getline( in  , task_number);
             number_of_task = stoi(task_number);
             

             for( int j=0 ; j < number_of_task ; ++j){
             
                  string task_name;
                  string task_status;
                  getline( in , task_name);
                  getline( in , task_status);

                  

                  if( task_status == "pending"){

                        task new_task(task_name,0);
                        temp_stu.add_task( val , new_task);
                        
                  }
                  else{
                        task new_task(task_name,1);
                        temp_stu.add_task( val , new_task);

                  }
             
             }                  
         }

         students.push_back(temp_stu);

      }
  
}

void save_output(){

      ofstream assignment_file("data/assignments.txt");
      for ( auto val : assignments){

             assignment_file<<val.getname()<<endl;
             assignment_file<<val.getdescription()<<endl;
             assignment_file<<val.get_it_deadline()<<endl;
             assignment_file<<val.get_fin_deadline()<<endl;

      }
      assignment_file.close();

      ofstream reviewer_file("data/reviewers.txt");
      for( auto val : reviewers){
         
             reviewer_file<<val.getid()<<endl;
             reviewer_file<<val.get_password_hash()<<endl;

      }
      reviewer_file.close();

      ofstream student_file("data/students.txt");
      for( auto val : students){
       
             student_file<<val.getid()<<endl;
             student_file<<val.get_password_hash()<<endl;

             for( auto ass : assignments){

                 switch( val.get_status(ass) ){
                     
                     case(PENDING):
                     student_file<<"pending"<<endl;
                     break;
                     case(IN_ITERATION):
                     student_file<<"in_iteration"<<endl;
                     break;
                     case(COMPLETED):
                     student_file<<"complete"<<endl;
                     break;

                 }

                 student_file<<val.get_link(ass , 0);
                 student_file<<val.get_task_count(ass)<<endl;
                 vector <task> tasks = val.get_task_vector(ass);
                 for( auto t : tasks){
   
                        student_file<<t.name<<endl;
                        if( t.completed){
                               student_file<<"complete"<<endl;
                        }
                        else student_file<<"pending"<<endl;

                 }


             }

      }
      
}


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

//    case 7:
//    for( auto val : students){
        
//         cout << val.getid() << endl;
//         cout << val.get_password_hash() << endl;

//    }
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
                  cout << "Desciption : " <<  cur_ass.getdescription() << endl;

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
                                
                                int in5;
                                string task_name;

                                while( in5!=6)
                                {
                                cout << "Assignment selected : " << cur_ass.getname() << endl;
                                cout << "Student Selected : "<< temp->getid() << endl << endl;
                                cout << "press 1 to view tasks" << endl;
                                cout << "press 2 to change task status" << endl;
                                cout << "press 3 to add new tasks" << endl;
                                cout << "press 4 to change assignment status" << endl;
                                cout << "press 5 to get submission_link"<<endl;
                                cout << "press 6 to go back" << endl;
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
                                      switch(flag){
                                          case 0:
                                          temp->change_assignment_status( cur_ass , PENDING );
                                          break;
                                          case 1:
                                          temp->change_assignment_status( cur_ass , IN_ITERATION );
                                          break;
                                          case 2:
                                          temp->change_assignment_status( cur_ass , COMPLETED );
                                          break;
                                        
                                      }
                                      cout << "set successfully" << endl;
                                      break;
                                      
                                      case 5:
                                      temp->get_link( cur_ass);
                                      break;


                                }

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
           cout << "press 3 to submit an assignment"<<endl;
           cout<< "press 5 to exit" << endl;

              cin>>in;
              string repo_link;
              int assignment_no;

              switch(in){
  
                case 1:
                cur_student.see_all_status();
                break;

                case 2:
                cur_student.get_all_tasks();
                break;
                
                case 3:
                cout << "Enter assignment Number: ";
                
                cin>>assignment_no;
                cout << "Enter the Github repo link or google docs link : ";
                cin>>repo_link;
                cur_student.set_submission( assignment_no , repo_link , students);
                cout << "set successfully!" << endl;


                case 5:
                logged_in_as = NOONE;
                break;

              }

           }



    }

   cout << endl << endl << endl;
   if(logged_in_as == NOONE && input!=5)project();


}

int main(){

     get_input();
     project();
     save_output();

     return 0;
}