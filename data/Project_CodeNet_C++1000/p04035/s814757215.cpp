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

  ll n, l;
  cin >> n >> l;
  vector<ll> rope(n);
  for (int i = 0; i < n; i++) cin >> rope[i];

  ll len_rope = 0;
  int cut;
  bool fl = false;
  for (int i = 0; i < n-1; i++) {
    len_rope = rope[i] + rope[i+1];
    if (len_rope >= l) {
      cut = i+1;
      fl = true;
      break;
    }
  }

  if (!fl) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;
  for (int i = 0; i < cut-1; i++) cout << i+1 << endl;
  for (int i = n-1; i >= cut; i--) cout << i << endl;  
}
