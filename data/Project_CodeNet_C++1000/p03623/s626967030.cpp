#include<iostream>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(x>a)
    a=x-a;
  else
    a=a-x;
  if(x>b)
    b=x-b;
  else
    b=b-x;
  if(a>b)
    cout<<"B"<<endl;
  else
    cout<<"A"<<endl;
}