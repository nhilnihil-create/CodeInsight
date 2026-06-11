#include <iostream>
using namespace std;
int main(){
  int a,b,h;
  cin>>a>>b>>h;
  if(a==b&&b==h) cout<<1;
  else if(a==b||b==h||h==a) cout<<2;
  else cout<<3;
}