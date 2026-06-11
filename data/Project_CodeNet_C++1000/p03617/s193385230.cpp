#include <bits/stdc++.h>
using namespace std;

int main() {
  long long q,h,s,d,n;
  cin>>q>>h>>s>>d>>n;
  long long ans=0;
  long long two=min({q*8,h*4,s*2,d});
  long long x=n/2;
  n%=2;
  ans+=two*x;
  if(n%2==0) cout<<ans<<endl;
  else cout<<min({ans+q*4,ans+h*2,ans+s})<<endl;
}
