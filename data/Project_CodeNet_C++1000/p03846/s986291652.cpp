#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<vector<ll>> Matrix;

const char wall = '#';
vector<vector<char>> fields;
vector<vector<bool>> used;
vector<vector<ll>> dist;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

vector<ll> A;
// vectorのリサイズ
// A.resize(N);

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a*b/gcd(a, b);}

const int MOD = 1000000007;
 
long long fastpow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> exp(n);
  if (n % 2) {
    rep(i, n/2) {
      exp[i] = n-1-2*i;
      exp[n-1-i] = n-1-2*i;
    }
    exp[n/2] = 0;
  } else {
    rep(i, n/2) {
      exp[i] = n-1-2*i;
      exp[n-1-i] = n-1-2*i;
    }
  }

  sort(a.begin(), a.end());
  sort(exp.begin(), exp.end());

  rep(i, n) {
    if (a[i] != exp[i]) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << fastpow(2, n/2) << endl;
  return 0;
}
