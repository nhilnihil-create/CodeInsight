#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// lib by snuke
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


int main() {
	int n;
	long long k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	rep(i, n) {
		ll t;
		cin >> t;
		a[i+1] = a[i] + t - k;
	}
	vector<ll> b = a;
	sort(b.begin(), b.end());
	map<ll, int> trans;
	rep(i, n + 1) trans[b[i]] = i;
	BIT<ll> d(n + 1);
	for(ll v: a) d.add(trans[v]);
	ll ans = 0;
	for(ll v: a) {
		d.add(trans[v], -1);
		ans += d.sum(trans[v], n + 1);
	}
	cout << ans << endl;
}
