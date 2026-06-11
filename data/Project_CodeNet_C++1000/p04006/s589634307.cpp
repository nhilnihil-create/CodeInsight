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

ll n, x;

vector<ll> a;

ll mans = 1e9*1e8;

vector<vector<ll> > mmin;

int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);

  cin >> n >> x;

  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  mmin.resize(n);
  for (int i = 0; i < n; i++) {
    mmin[i].resize(n);
  }

  for (int i = 0; i < n; i++) {
    mmin[i][i] = a[i];
    for (int j = (i+1)%n; j != i; j = (j+1)%n) {
      mmin[i][j] = min(mmin[i][(j-1+n)%n], a[j]);
    }
  }

  /*for (int i =0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mmin[i][j] << ' ';
    } cout << endl;
  }*/

  for (int i = 0; i < n; i++) {
    ll cans = x*i;
    for (int j = 0; j < n; j++) {
      cans += mmin[j][(j+i)%n];
    }

    mans = min(mans, cans);
    //cerr << "for  " << i << " " << cans << endl;
  }

  cout << mans << endl;
}

