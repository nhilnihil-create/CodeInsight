#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;
const lli e3 = 1 << 13;
const lli INF = 1ll << 63;

lli n;
string s;
lli dp[e3];
lli dp_[e3];

lli powl(lli x,lli r,lli mod = mod){
  lli ret = 1;
  for(;r != 0;r >>= 1){
    if(r&1 != 0) ret *= x,ret %= mod;
    x *= x,x %= mod;
  }
  return ret;
}

lli inverse(lli x,lli mod = mod){
  return powl(x,mod-2,mod);
}

int main(){
  cin >> n;
  cin >> s;
  dp[0] = 1;
  for(lli i = 0;i < n;i++){
    for(lli j = 0;j <= n;j++){
      dp_[j+1] += dp[j];
      dp_[j+1] += dp[j];
      dp_[max(j-1, 0ll)] += dp[j];
    }

    for(lli j = 0;j <= n;j++){
      dp[j] = dp_[j]%mod;
      dp_[j] = 0;
    }
  }
  cout << (dp[s.size()]*inverse(powl(2,(lli)(s.size()))))%mod << endl;

}
