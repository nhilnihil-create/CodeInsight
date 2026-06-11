#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
using namespace __gnu_pbds;
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using pl = pair<ll, ll>;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll t, n;
ll step = 45000;

vector<ll> anw;
vector<ll> ssums;

ll mod = 998244353;

int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);

  cin >> n;

  vector<ll> a;
  vector<ll> b;

  ll cur = 1;

  for (int i = 0; i < n; i++) {
    a.push_back(cur);
    cur += step;
  }

  for (int i = n-1;  i>=0; i--) {
    b.push_back(a[i]);
  }

  cur = 1;
  ll x; cin >> x;
  for (int i = 1; i < n; i++) {
    cin >> x; x--;
    b[x] += cur;
    cur++;

  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  } cout << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << ' ';
  } cout << endl;
}

