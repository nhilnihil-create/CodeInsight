#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){

  int a,b;
  string op;
  cin>>a>>op>>b;
  if(op=="+")cout<<a+b;
  else cout<<a-b;
  return 0;
}