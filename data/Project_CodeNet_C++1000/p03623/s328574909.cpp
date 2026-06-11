#include <iostream>

using namespace std;

int main()
{

int x,a,b;
cin>>x>>a>>b;
if(x>a&&x>b){
       if(x-a<x-b)
              cout<<"A";
              else
                     cout<<"B";
}
if(x>a&&x<b){
       if(x-a<b-x)
              cout<<"A";
              else
                     cout<<"B";
}
if(x<a&&x>b)
{
       if(a-x<x-b)
              cout<<"A";
       else
              cout<<"B";
}
if(x<a&&x<b)
{
       if(a-x<b-x)
              cout<<"A";
       else
              cout<<"B";
}



    return 0;
}