#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  if(a<10)cout<<"ABC00"<<a;
  else if(a<100)cout<<"ABC0"<<a;
  else cout<<"ABC"<<a;
}