#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  int b=a%10;
  a=a/10;
  if(a==9||b==9)
    cout<<"Yes";
  else 
    cout<<"No";
  return 0;
}