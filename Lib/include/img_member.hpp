#ifndef IMG_MEMBER_HPP
#define IMG_MEMBER_HPP

using namespace std;
#include <string>
#include <vector>
#include <set>

vector <assignment> assignments;

enum status{
 
   PENDING,
   IN_ITERATION,
   COMPLETED,

};

enum Log{
  
   NOONE,
   STUDENT,
   REVIEWER,

};

class img_member{
  
     public:

   //   img_member();
   //   ~img_member();
   //   img_member( const img_member &member);


     int check_member(string id , string password);
     void display(img_member &member);
     string getid();
     void set_profile( string id , string password , int flag);
     void set_existing_profile( string id , size_t password_hash , int flag);
     size_t get_password_hash();
     
     private:
     
     string id;
     size_t password_hash;
     int flag;


};


assignment get_assignment( int number );


#endif