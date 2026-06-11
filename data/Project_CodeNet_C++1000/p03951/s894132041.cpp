#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

int main(){
  int n;cin >> n;
  string s,t;cin >> s >> t;
  int same=n;
  reverse(s.begin(),s.end());
  while(same>0){
  bool can=true;
  rep(i,same){
    if(s[same-i-1]!=t[i]){
      can=false;
      break;
    }
  }
  if(!can){
    same--;s.pop_back();t.pop_back();
  }
  if(can)break;
  }
  cout << 2*n-same << endl;
}