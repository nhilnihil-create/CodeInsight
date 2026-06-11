#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <stack>
#include <iomanip>
#include <cmath>


using namespace std;


typedef long long ll;
typedef long double ld;


const int MAXN = 5001;
const ll MOD = 1000000007ll;;


int N, L;
ll memo[MAXN][MAXN];


ll modSum(ll a, ll b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}


ll modProd(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}


ll getPow(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPow(x, e/2);
    return modProd(tmp, tmp);
  } else {
    ll tmp = getPow(x, e-1);
    return modProd(tmp, x);
  }
}


ll DP(int keys, int len) {
  if (keys == len) return getPow(2, keys);
  if (keys < len) return 0;
  if (memo[keys][len] != -1) {
    return memo[keys][len];
  }
  ll v = DP(keys-1, len+1);
  if (len != 0) {
    v = modSum(v, modProd(2, DP(keys-1, len-1)));
  } else {
    v = modSum(v, DP(keys-1, len));
  }
  return memo[keys][len] = v;
}


void input() {
  cin >> N;
  string tmp;
  cin >> tmp;
  L = (int)tmp.size();
}


void preprocess() {
  for (int i = 0 ; i < MAXN ; i++) {
    for (int j = 0 ; j < MAXN ; j++) {
      memo[i][j] = -1;
    }
  }
}


ll getAns() {
  if (N < L) {
    return 0;
  }
  if (N == L) {
    return 1;
  }
  return modProd(DP(N, L), getPow(2, L * (MOD - 2)));
}


void solve() {
  cout << getAns();
  //cerr << "DP = " << DP(N, L) << "\n";
}






int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int T;
//  cin >> T;
  T = 1;

  for (int i = 0 ; i < T ; i++) {
    input();
    preprocess();
    solve();
  }

  return 0;
}
