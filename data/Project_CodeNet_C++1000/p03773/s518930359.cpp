#include<iostream>

using namespace std;

int main(void)
{
  int a,b; cin>>a>>b;
  int start=a+b;
  
  if(start>=24){
    start-=24;
  }
  
  cout<<start<<endl;
  return 0;
}