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


const ll MOD = 1000000007ll;


ll modSum(ll a, ll b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}


ll modProd(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}


ll getPowMod(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPowMod(x, e/2);
    return modProd(tmp, tmp);
  } else {
    ll tmp = getPowMod(x, e-1);
    return modProd(tmp, x);
  }
}


ll getPow(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPow(x, e/2);
    return tmp * tmp;
  } else {
    ll tmp = getPow(x, e-1);
    return tmp * x;
  }
}


bool isEven(ll x) {
  ll tmp = ((x % 2) + 2) % 2;
  return tmp == 0;
}


ll getSumOfDigitsInBase(ll n, ll b) {
  ll ret = 0;
  while (n > 0) {
    ret += n % b;
    n /= b;
  }
  return ret;
}












const int MAXN = 100002;
const int MAXLOG = 20;


ll N, L, Q;
vector<ll> X;
ll memo[MAXN][MAXLOG];



void input() {
  cin >> N;
  ll tmp;
  for (int i = 0 ; i < N ; i++) {
    cin >> tmp;
    X.push_back(tmp);
  }
  cin >> L >> Q;
}

void preprocess() {
  for (int l = 0 ; l < MAXLOG ; l++) {
    memo[N][l] = N;
  }
  for (int i = N-1 ; i >= 0 ; i--) {
    auto it = lower_bound(X.begin(), X.end(), X[i]+L+1);
    if (it != X.end()) {
      it--;
    }
    memo[i][0] = (int)(it-X.begin());
    for (int l = 1 ; l < MAXLOG ; l++) {
      memo[i][l] = memo[memo[i][l-1]][l-1];
    }
  }
  /*
  for (int i = 0 ; i <= N ; i++) {
    for (int l = 0 ; l < MAXLOG ; l++) {
      cout << "memo[" << i << "][" << l << "] = " << memo[i][l] << "\n";
    }
  }
  */
}


ll getAns(ll from, ll to) {
  ll ans = 0;
  ll at = from;
  for (int i = MAXLOG-1 ; i >= 0 ; i--) {
    if (memo[at][i] <= to) {
      ans += getPow(2, i);
      at = memo[at][i];
    }
  }
  if (at != to) {
    ans++;
  }
  return ans;
}


void solve() {
  int a, b;
  for (int i = 1 ; i <= Q ; i++) {
    cin >> a >> b;
    cout << getAns(min(a, b)-1, max(a, b)-1) << "\n";
  }
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
