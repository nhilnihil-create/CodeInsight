#include<iostream>
using namespace std;
int main()
{
  int x,a,b;
  cin>>x>>a>>b;
  int c=a-x;
  int d=b-x;
  if(c<0){
    c=-1*c;
    if(d<0){
      d=-1*d;
      if(c>=d){
        cout<<"B";
      }
      else{
        cout<<"A";
      }
    }
    else{
      if(c>=d){
        cout<<"B";
      }
      else{
        cout<<"A";
      }
    }
  }
  else{
    if(d<0){
      d=-1*d;
      if(c>=d){
        cout<<"B";
      }
      else{
        cout<<"A";
      }
    }
    else{
      if(c>=d){
        cout<<"B";
      }
      else{
        cout<<"A";
      }
    }
  }
}