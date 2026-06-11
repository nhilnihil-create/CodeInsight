#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bs2int(bs) (int)((bs).to_ulong())
#define DEBUG(X) cerr<<"  "<<#X<<" = "<<X<<endl;
#define DUMP(A, n) for (auto x=begin(A); x!=begin(A)+n;x++){cout <<*x<< ' ';} cout<<endl;
#define DUMPP(A, n, m) for (auto x=begin(A); x != begin(A)+n;x++) {for (auto y=begin(*x); y != begin(*x)+m;)cout <<*y++<< ' '; cout<<endl;};
#define DUMPM(M) for (auto itr=mp.begin(); itr!=mp.end(); itr++) {cout<<itr->first<<" -> "<<itr->second<<endl;}
#define FOR(i,x,y) for(int i=(x);i<(int)(y);i++)
#define FORP(i,x,y) for(int i=(x);i<=(int)(y);i++)
#define REP(i,y) for(int i=0;i<(int)(y);i++)
#define REPP(i,y) for(int i=1;i<=(int)(y);i++)
#define REPB(i,n) for(int i=(int)(n)-1;i>=0;i--)

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
};

const int mod = 1000000007;

template<int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
  static vector<Modulo<M, true>> v1 = {1}, v2 = {1};
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Modulo<M, true>(i));
      v2.push_back(v2.back() / Modulo<M, true>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M = mod> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

using Mod = Modulo<mod, true>;

map<int, int> mp;

int main() {
  int n; cin>>n;
  int p,q;
  REP(i,n+1) {
    int a; cin>>a;
    if (mp[a]!=0)
      p=mp[a]-1, q=i;
    mp[a] = i+1;
  }
  FORP(k,1,n+1) {
    if ((n+1)-(q-p)==k)
      cout << (int)(comb(n+1, k) - comb((n+1)-(q-p), k)) << endl;
    else if (k<n+1) {
      cout << (int)(comb(n+1, k) - comb((n+1)-(q-p+1), k-1)) << endl;
    } else if (k==n+1)
      cout << (int)comb(n+1, k) << endl;
  }
}
