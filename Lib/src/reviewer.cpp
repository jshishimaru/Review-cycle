#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/include/reviewer.hpp"
#include <iostream>
using namespace std;

// reviewer::reviewer(){};
// reviewer::~reviewer(){};
// reviewer::reviewer( const reviewer &reviewer){};

int set_member(string id , string password , int flag , vector <student> &students , vector <reviewer> &reviewers){
   
 if( flag ){

     student temp;

     //check for same ids
     for(auto val : students){
        
          if( id == val.getid() ){
              return 1;
          }
        
     }

     temp.set_profile( id , password , flag);
     students.push_back(temp);

     return 0;     

    }
    
    
    else{

     reviewer temp;

     //check for same ids
     for(auto val : reviewers){
        
          if( id == val.getid() ){
              return 1;
          }
        
     }

     temp.set_profile( id , password , flag);
     reviewers.push_back(temp);

     return 0;     

    }

    // return code 1 means user already exists
    // return code 0 means new user has been created


}

int reviewer_login( string id , string password , reviewer &cur_reviewer , vector <reviewer> &reviewers){
   
     for( auto val : reviewers){
  
       if( id == val.getid()){

               if( val.check_member(id,password) ){
                  
                   cur_reviewer = val;
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

int reviewer::add_assignment( vector <student> &students){
  
     string temp;
     cout << "Enter Assignment Name : ";
     cin>>temp;
     
     for( auto val : assignments){
     
           if ( temp == val.getname()){

                cout<<"Name already exists";
                return 1;

           }
     
     }
     string temp2;
     cout << "Enter Assignment Description : " << endl;
     cin>>temp2;

     string temp3;
     cout << "Enter the 1st Iteration deadline in DD-MM-YYYY : ";
     cin>>temp3;

     date deadline1;
     deadline1.setdate(temp3);

     string temp4;
     cout << "Enter the final deadline in DD-MM-YYYY : ";
     cin>>temp4;

     date deadline2;
     deadline2.setdate(temp4);

     assignment temp_ass;
     temp_ass.set_assignment( temp , temp2 , deadline1 , deadline2);

     assignments.push_back(temp_ass);
     cout << "Assignment Added!" << endl;   

     for( auto &val : students){
          
             val.set_status(temp_ass , PENDING);
             cout << "set for " << val.getid() << endl;

     }   
     
     return 0;

}

void reviewer::view_assignments(){
   
   for( auto val : assignments){
     
        cout << val.getnumber() << ". " << val.getname() << endl;
     
   
   }
  
}

void reviewer::view_status( assignment assignment , vector <student> students){
   
    for( auto val : students){
  
          cout << val.getid() << " - " ;
          
          switch( val.get_status(assignment)){
           
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

void reviewer::change_status( assignment assignment , vector <student> students){

     cout << "Enter Student name : ";
     string temp;
     cin>>temp;

     cout << "press 1 to set to PENDING"<<endl;
     cout << "press 2 to set to IN ITERATION"<<endl;
     cout << "press 3 to set to COMPLETE"<<endl;
        
     int in;
     cin>>in;

     for( auto &val : students){
          
          if( temp == val.getid() ){
            
             switch(in){
               case 1:
               val.set_status( assignment , PENDING);
               return;
               break;
               case 2:
               val.set_status(assignment ,  IN_ITERATION);
               return;
               break;
               case 3:
               val.set_status(assignment , COMPLETED);
               return;
               break;
             }

          }

     }

     cout << "No Student Found!" << endl;

}