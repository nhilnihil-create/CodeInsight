#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, W;

int main(){
  cin >> N >> W;
  vector<pair<ll, ll> > wv(N);
  vector<ll> kaz(4, 0LL);
  
  for(ll i = 0; i < N; i++){
    ll w, v; cin >> w >> v;
    wv[i] = make_pair(w, -v);
  }
  ll wmi = wv[0].first;
  
  sort(wv.begin(), wv.end());
  for(ll i = 0; i < N; i++){
    kaz[wv[i].first-wmi]++;
    //cout << "w = " << wv[i].first << ",v = " << -wv[i].second << endl;
  }
  ll s2 = kaz[0];
  ll s3 = s2 + kaz[1];
  ll s4 = s3 + kaz[2];
  
  ll ans = 0LL;
  ll w1 = 0LL, v1 = 0LL;
  ll w2 = 0LL, v2 = 0LL;
  ll w3 = 0LL, v3 = 0LL;
  ll w4 = 0LL, v4 = 0LL;
  for(ll i = 0; i <= kaz[0]; i++){
    if(i) {w1 += wv[i-1].first; v1 -= wv[i-1].second;}
    for(ll j = 0; j <= kaz[1]; j++){
      if(j) {w2 += wv[s2 + j-1].first; v2 -= wv[s2 + j-1].second;}
      else {w2 = 0; v2 = 0;}
      for(ll k = 0; k <= kaz[2]; k++){
        if(k) {w3 += wv[s3 + k-1].first; v3 -= wv[s3 + k-1].second;}
        else {w3 = 0; v3 = 0;}
        for(ll l = 0; l <= kaz[3]; l++){
          if(l) {w4 += wv[s4 + l-1].first; v4 -= wv[s4 + l-1].second;}
          else {w4 = 0; v4 = 0;}
          if(w1 + w2 + w3 + w4 <= W) ans = max(ans, v1 + v2 + v3 + v4);
        }
      }
    }
  }
  cout << ans;
}