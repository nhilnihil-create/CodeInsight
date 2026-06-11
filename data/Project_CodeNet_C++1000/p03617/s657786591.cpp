#include <bits/stdc++.h>
using namespace std;

int main() {
  long long q,h,s,d,n;
  cin >>q>>h>>s>>d>>n;
  long long yasui1=min({q*4,h*2,s});
  long long yasui2=min(n/2*d,yasui1*n);
  long long kotae=LLONG_MAX;
  if(n%2==0)kotae=min(yasui1*n,yasui2);
  else kotae=min(yasui1*n,n/2*d+yasui1);
  cout<<kotae<<endl;
  return 0;
}
