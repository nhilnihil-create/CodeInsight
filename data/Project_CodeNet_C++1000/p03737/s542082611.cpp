#include<bits/stdc++.h>
using namespace std;

int main(){
  int n='A'-'a';
  string s,t,u;
  cin >> s >> t >> u;
  char a,b,c;
  a=s.at(0)+n;
  b=t.at(0)+n;
  c=u.at(0)+n;
  cout << a << b << c << endl;
}