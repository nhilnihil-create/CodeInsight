#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;
  string S;
  cin>>x>>a>>b;
  if(abs(x-a)>abs(x-b)) S="B";
  else S="A";
  
  cout<<S<<endl;
}