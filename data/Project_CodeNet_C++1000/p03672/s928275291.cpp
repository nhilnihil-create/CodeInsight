#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int c=0;
  for(int i=1;i<s.size()/2;i++) if(s.substr(0,i)==s.substr(i,i)) c=2*i;
  cout<<c;
}
