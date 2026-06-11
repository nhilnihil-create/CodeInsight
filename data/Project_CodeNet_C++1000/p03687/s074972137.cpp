#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  string s;cin >> s;
  map<char,ll> m;
  rep(i,(ll)s.size()) m[s.at(i)]++;

  ll ans;
  if( s.size()%2 == 0 ) ans = (ll)s.size()/2;
  else ans = (ll)s.size()/2+1;

  for(auto p : m ){
    ll score = 0;
    char c = p.first;
    for(ll i=(ll)s.size()-1;i>=0;--i){
      if( s.at(i) == c ){
        ll cnt = 1;
        for(ll j=i+1;j<(ll)s.size();++j){
          if( s.at(j) == c ){
            --cnt;
            score = max(score,cnt);
            break;
          }else if( j == (ll)s.size()-1 ){
            score = max(score,cnt);
          }
          ++cnt;
        }
        cnt = 1;
        for(ll j=i-1;j>=0;--j){
          if( s.at(j) == c ){
            --cnt;
            score = max(score,cnt);
            break;
          }else if( j == 0 ){
            score = max(score,cnt);
          }
          ++cnt;
        }
      }
    }
    ans = min(ans,score);
  }
  cout << ans << endl;
  return 0;
}


