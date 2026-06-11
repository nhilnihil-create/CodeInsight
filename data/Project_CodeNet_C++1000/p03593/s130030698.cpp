#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
bool custom1 (pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first);
}
bool custom2(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}

const int MAX = 200005;
const long long MOD = 1000000007;
const long long MODMOD = 998244353;
const double PI = acos(-1);

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
struct UnionFind {
  vector<int> p;
  vector<int> s;
  void init(int n) {
    p.resize(n, -1);
    s.resize(n, 1);
  }
  int find(int n) {
    if(p[n] == -1) return n;
    else return find(p[n]);
  }
  int size(int n) {
    return s[find(n)];
  }
  void unite(int n, int m) {
    int pn = find(n);
    int pm = find(m);
    if(pn == pm) return;
    if(s[pn] > s[pm]) {
      s[pn] = s[pn] + s[pm];
      p[pm]= pn;
    } else {
      s[pm] = s[pm] + s[pn];
      p[pn] = pm;
    }
  }
};

long long gcd(long long a, long long b) {
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}
int main() {
  int h, w;
  cin >> h >> w;
  vector<int> al(26);
  rep(i, h * w) {
    char c;
    cin >> c;
    al[c-'a']++;
  }
  int odd = 0;
  int even = 0;
  int four = 0;
  bool yes = true;
  if(h % 2 == 0 && w % 2 == 0) {
    rep(i, al.size()) {
      if(al[i] % 4 != 0) yes = false;
    }
  }
  else if(h % 2 == 1 && w % 2 == 1) {
    rep(i, al.size()) {
      if(al[i] % 2 == 1) {
        odd++;
        al[i] -= 1;
      }
      if(al[i] % 4 == 2) four += 2;
    }
    if(odd != 1) yes = false;
    if(four > h + w - 2) yes = false;
  }
  else {
    rep(i, al.size()) {
      if(al[i] % 2 == 1) odd++;
      else if(al[i] % 4 != 0) four+=2;
    }
    if(odd != 0) yes = false;
    if(h % 2 == 0) {
      if(four > h) yes = false;
    }
    else if(four > w) yes = false;
  }
  if(yes) cout << "Yes" << endl;
  else cout << "No" << endl;
}

