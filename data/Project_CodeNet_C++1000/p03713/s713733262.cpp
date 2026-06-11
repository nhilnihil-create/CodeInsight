#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
ll inf = 1e9+7;

ll gcd(ll a, ll b){
  return (b != 0) ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
  return (a/gcd(a,b))*b;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll h, w;
  cin >> h >> w;
  if(w*h %3 == 0){cout << 0 << "\n"; return 0;}
  ll ans = inf;
  ll k = max(h, w);
  ll l = min(h, w);
  for(ll i = 1; i < k; ++i){
    ll s1[3], s2[3];
    s1[0] = i*l; s1[1] = (k-i)*(l/2); s1[2] = (k-i)*((l+1)/2);
    sort(s1, s1+3);
    ans = min(ans, s1[2]-s1[0]);
    s2[0] = i*l; s2[1] = l*((k-i)/2); s2[2] = l*((k-i+1)/2);
    sort(s2, s2+3);
    ans = min(ans, s2[2]-s2[0]);
  }
  swap(k, l);
  for(ll i = 1; i < k; ++i){
    ll s1[3], s2[3];
    s1[0] = i*l; s1[1] = (k-i)*(l/2); s1[2] = (k-i)*((l+1)/2);
    sort(s1, s1+3);
    ans = min(ans, s1[2]-s1[0]);
    s2[0] = i*l; s2[1] = l*((k-i)/2); s2[2] = l*((k-i+1)/2);
    sort(s2, s2+3);
    ans = min(ans, s2[2]-s2[0]);
  }
  
  cout << ans << "\n";
  return 0;
}   