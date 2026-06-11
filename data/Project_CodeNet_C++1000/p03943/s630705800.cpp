#include <iostream>
using namespace std;
int main(){
  int a,b,h;
  cin>>a>>b>>h;
  if(a+b==h) cout<<"Yes";
  else if(b+h==a) cout<<"Yes";
  else if(h+a==b) cout<<"Yes";
  else cout<<"No";
}