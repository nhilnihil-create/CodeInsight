#include<iostream> 
using namespace std; 
  
int main ()
{
   char a,b;
   cin>>a>>b;
   if(a=='H')
   cout<<b;
   else
   {if(b=='H')
   cout<<"D";
   else
   cout<<"H";
   }
    return 0;
}