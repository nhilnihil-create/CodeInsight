#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;
  s=min(s,min(q*4,h*2));
  
  ll ans=s*(n%2);
  
  ans+=min(d,s*2)*(n/2);
  
  cout << ans << endl;
}