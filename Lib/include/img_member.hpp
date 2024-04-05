#ifndef IMG_MEMBER_HPP
#define IMG_MEMBER_HPP

using namespace std;
#include <string>
#include "assignment.hpp"
#include <vector>

vector <assignment> assignments;

enum status{
 
   PENDING,
   IN_ITERATION,
   COMPLETED,

};

class img_member{
  
     public:

     virtual bool check_member(string id , string password);
     virtual void set_member( string id , string password , int flag);
     virtual void display(img_member &member);
     
     private:
     
     string id;
     string password;
     int flag;


};

void addmember();




#endif