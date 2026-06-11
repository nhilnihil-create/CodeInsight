#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long a,b;
  cin>>a>>b;
  if(2*a>=b)cout<<b/2<<endl;
  else{
    long long kotae=a;
    b-=2*a;
    kotae+=b/4;
    cout<<kotae<<endl;
  } 
  return 0;
}