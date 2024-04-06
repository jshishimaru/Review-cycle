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
     
     private:
     
     string id;
     string password;
     int flag;


};





#endif