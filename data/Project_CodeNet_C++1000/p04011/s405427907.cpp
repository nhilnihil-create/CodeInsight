#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  long long kotae=0;
  if(a<=b)kotae=a*c;
  else kotae=b*c+(a-b)*d;
  cout<<kotae<<endl;
  return 0;
}