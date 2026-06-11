#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  ll q,h,s,d;cin >> q >> h >> s >> d;
  q *= 4;
  h *= 2;
  s = min(s,min(q,h));
  ll n;cin >> n;
  ll ans = 0;
  if( 2*s > d ){
    ans += n/2*d;
    if( n%2 != 0 ) ans += s;
  }else{
    ans = n*s;
  }
  cout << ans << endl;


  return 0;
}