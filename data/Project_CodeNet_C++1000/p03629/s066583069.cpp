#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;
 
const ll N=2e5+10;
mat v(26);
ll n;
string s;
ll dp[N];
 
ll solve(ll cur) {
  if(cur==n) {
    return 0;
  }
  ll &ret=dp[cur];
  if(ret!=-1) {
    return ret;
  }
  ret=1e9;
  for(ll i=0;i<26;i++) {
    ll idx=upper_bound(v[i].begin(),v[i].end(),cur)-v[i].begin();
    ll nex=v[i][idx];
    ret=min(ret,solve(nex)+1);
  }
  return ret;
}
 
void build(ll cur) {
  if(cur==n) {
    return ;
  }
  for(ll i=0;i<26;i++) {
    ll idx=upper_bound(v[i].begin(),v[i].end(),cur)-v[i].begin();
    ll nex=v[i][idx];
    if(solve(cur)==solve(nex)+1) {
      cout << (char)(i+'a');
      build(nex);
      break;
    }
  }
}
 
int main() {
  memset(dp,-1,sizeof(dp));
  cin >> s;
  s="#"+s;
  n=s.size();
  for(ll i=1;i<n;i++) {
    v[s[i]-'a'].push_back(i);
  }
  for(ll i=0;i<26;i++) {
    v[i].push_back(n);
  }
  build(0);
}