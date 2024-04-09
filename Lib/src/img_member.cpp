#include "/home/jshishimaru/development/img_lec/Review_Cycle/Lib/include/student.hpp"
using namespace std;

// img_member::img_member(){};
// img_member::img_member( const img_member &member){
 
//     this->id = member.id;
//     this->password = member.password;
//     this->flag = member.flag;

// }
// img_member::~img_member(){};

void img_member::set_profile( string id , string password , int flag){
  
    this->id = id;
    this->password = password;
    this->flag = flag;

}

string img_member::getid(){
 
    return this->id;

}

int img_member::check_member( string id , string password ){
       
        if( (id == this->id) && (password == this->password) ){
               return 1;
        }
        else{
               return 0;
        }

}

assignment get_assignment( int number ){

     assignment tmp;
 
      for ( auto val : assignments){
          
             tmp = val;
  
             if ( number == val.getnumber() ){

                   return val;

             }

      }
      return tmp;

   }
