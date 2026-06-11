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


ll modSubtract(ll a, ll b) {
  return (((a % MOD) - (b % MOD)) + MOD + MOD) % MOD;
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


ll getInverse(ll x) {
  return getPowMod(x, MOD-2);
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


vector<int> getKMP(string &s) {
  int len = (int)s.size();
  vector<int> ret (len, 0);
  for (int i = 1 ; i < len ; i++) {
    int at = ret[i-1];
    while (at > 0 && s[i] != s[at]) {
      at = ret[at-1];
    }
    if (s[i] == s[at]) {
      at++;
    }
    ret[i] = at;
  }
  return ret;
}


string getSubstring(string &s, int from, int to) {
  int l = to-from+1;
  if (l <= 0) {
    return "";
  }
  return s.substr(from, l);
}

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}












const int MAXN = 100001;


int N, T;
ll maxDiff;
ll ar[MAXN], rlMax[MAXN];
map<ll, int> freq;


void input() {
  cin >> N >> T;
  for (int i = 1 ; i <= N ; i++) {
    cin >> ar[i];
  }
}


void preprocess() {
  for (int i = 1 ; i <= N ; i++) {
    freq[ar[i]]++;
  }
  rlMax[N] = ar[N];
  for (int i = N-1 ; i >= 1 ; i--) {
    rlMax[i] = max(rlMax[i+1], ar[i]);
  }
  maxDiff = 0;
  for (int i = 1 ; i <= N ; i++) {
    maxDiff = max(maxDiff, rlMax[i] - ar[i]);
  }
}


void solve() {
  //cerr << "maxDiff = " << maxDiff << "\n";
  int ans = 0;
  for (int i = 1 ; i <= N ; i++) {
    if (freq[ar[i]] > 0 && freq[ar[i]+maxDiff] > 0) {
      freq[ar[i]+maxDiff]--;
      ans++;
    }
    freq[ar[i]]--;
  }
  cout << ans;
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
