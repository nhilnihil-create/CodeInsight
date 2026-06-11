#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const ll mod = 1000000007;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n+1);
    s[0] = 0;
    rep(i, n) s[i+1] = s[i] + a[i];
    vector<ll> x(n+1);

    rep(i, n+1) {
        ll v = s[i] - k * i;
        x[i] = v;        
    }
    {
        map<ll, ll> mp;
        rep(i, n+1) mp[x[i]] = 0;
        int id = 0;
        for (auto& m: mp) {
            m.second = id++;
        }
        rep(i, n+1) {
            x[i] = mp[x[i]];
        }
    }

    BIT<ll> bit(n+1);
    ll ans = 0;
    rep(i, n+1) {
        ans += bit.sum(x[i]);
        bit.add(x[i]);
    }

    
    
    
    
    cout << ans << endl;
    return 0;
}
