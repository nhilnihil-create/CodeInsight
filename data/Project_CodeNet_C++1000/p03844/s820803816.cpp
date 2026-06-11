#include<iostream>
using namespace std;
int main(){
  int a,b;cin>>a;
  char c;cin>>c;
  cin>>b;
  if(c=='+')a+=b;
  else a-=b;
  cout<<a<<endl;
  return 0;
}