#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;


template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main()
{
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> s(n+1),u(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];
    rep(i,n+1) u[i] = s[i] - k*i;

    vector<ll> v(n+1),hoge;//座圧：u -> v
    rep(i,n+1) hoge.emplace_back(u[i]);
    sort(all(hoge));
    hoge.erase(unique(all(hoge)), hoge.end());
    rep(i,n+1) v[i] = lower_bound(all(hoge),u[i]) - hoge.begin();

    BinaryIndexedTree<int> b(n+1);
    ll res = 0;
    rep(i,n+1) {
        res += b.sum(v[i]);
        b.add(v[i],1);
    }

    cout << res << endl;
    return 0;
}