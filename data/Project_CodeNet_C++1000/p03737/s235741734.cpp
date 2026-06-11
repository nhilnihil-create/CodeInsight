#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  char a_,b_,c_;
  cin>>a>>b>>c;
  a_=a[0];
  b_=b[0];
  c_=c[0];
  char x,y,z;
  x='A'+(a_-'a');
  y='A'+(b_-'a');
  z='A'+(c_-'a');
  cout<<x<<y<<z<<endl;
}
