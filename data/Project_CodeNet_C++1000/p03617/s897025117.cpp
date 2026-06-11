#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  ll q,h,s,d,n;
  cin>>q>>h>>s>>d>>n;
  ll one=min(4*q,min(2*h,s));
  ll ans;
  if(2*one<=d) ans=n*one;
  else{
    ans=(n%2==1 ? n/2*d+one : n/2*d);
  }
  cout<<ans<<endl;
  return 0;
}
