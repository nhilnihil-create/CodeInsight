#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int n;
string s;
typedef long long ll;
const int mod = 1e9+7;

int pkt(ll b, ll e) {
  ll res = 1;
  while (e > 0) {
  	  if (e&1) {
  	  	  res *= b;
  	  	  res %= mod;
  	  }
  	  b*=b;
  	  b%=mod;
  	  e>>=1;
  }
  return res;
}

int f(int pos, int left) {
  if (left == 0) return pos == s.length();
  int &ret = dp[pos][left];
  if (ret>=0) return ret;
  ret = 0;
  ret += 2*f(pos+1, left-1);  ret %= mod;
  if (pos > 0) ret += f(pos-1, left-1);
  else ret += f(pos, left-1);
  ret %= mod;
  return ret;
}

int main() {
  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  ll ans = f(0, n);
  ll inv = pkt(pkt(2, s.length()) , mod-2);
  printf("%lld\n", (ans*inv)%mod);
}