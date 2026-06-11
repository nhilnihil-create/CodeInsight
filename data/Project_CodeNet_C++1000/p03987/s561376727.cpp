#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]-1] = i;
  }
  set<ll> done;
  done.insert(-1); done.insert(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int p = pos[i];
    int pleft = *(--done.lower_bound(p));
    int pright = *(done.lower_bound(p));
    done.insert(p);
    if (dbgflag) cout << pleft << " " << p << " " << pright << endl;
    sum += (ll)(i+1) * (p - pleft) * (pright - p);
  }

  cout << sum << endl; 
}
