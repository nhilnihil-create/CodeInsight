#include<iostream>
#include<iomanip>
using namespace std; 
 
int main ()
{
   double x,a,b;
   cin>>x>>a>>b;
   int desA,desB;
   desA=x-a;
   if(desA<0)
   {desA=desA*-1;}
   desB=x-b;
   if(desB<0)
   {desB=desB*-1;}
   if(desA>desB)
   cout<<"B";
   else
   cout<<"A";
    return 0;
}