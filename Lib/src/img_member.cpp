#include "../include/img_member.hpp"
using namespace std;

// img_member::img_member(){};
// img_member::img_member( const img_member &member){
 
//     this->id = member.id;
//     this->password = member.password;
//     this->flag = member.flag;

// }
// img_member::~img_member(){};

void img_member::set_profile( string id , string password , int flag){
  
    hash <string> password_hash_fn;
    this->id = id;
    this->password_hash = password_hash_fn(password);
    this->flag = flag;

}

string img_member::getid(){
 
    return this->id;

}

int img_member::check_member( string id , string password ){
       
       hash <string> password_hash_fn;
        if( (id == this->id) ){
                
               if( this->password_hash == password_hash_fn(password)){
                     return 1;
               }

        }
               cout << "correct hash : "<< this->get_password_hash()<<endl;
               cout << "your hash : " << password_hash_fn(password); 
               return 0;


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

size_t img_member::get_password_hash(){
       return this->password_hash;
}

void img_member::set_existing_profile( string id , size_t password , int flag){
 
       this->id = id;
       this->password_hash = password;
       this->flag = flag;

}

