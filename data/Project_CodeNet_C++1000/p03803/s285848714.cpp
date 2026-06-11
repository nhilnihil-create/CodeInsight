#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   int A, B;
   cin >>A >>B;
   if(A < B)
   {
       if(A == 1)
       printf("Alice");
       
       else
       printf("Bob");
   }
   if(A > B)
   {
       if(B == 1)
       printf("Bob");
       else
       printf("Alice");
   }
   if(A == B)
   printf("Draw");
}

