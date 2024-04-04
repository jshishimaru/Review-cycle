#ifndef IMG_MEMBER_HPP
#define IMG_MEMBER_HPP

using namespace std;
#include <string>

enum status{
 
   PENDING,
   IN_ITERATION,
   COMPLETED,

};

class img_member{
  
     public:

     bool check_member(string id , string password);
     void set_member( string id , string password , int flag);
     
     private:
     
     string id;
     string password;
     int flag;


};

void addmember();




#endif