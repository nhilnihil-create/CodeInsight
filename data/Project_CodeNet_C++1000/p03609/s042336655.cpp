#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  a-=b;
  if(a<0)a=0;
  cout<<a<<endl;
  return 0;
}