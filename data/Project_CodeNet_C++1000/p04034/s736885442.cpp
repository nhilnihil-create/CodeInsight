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

  int n, m;
  cin >> n >> m;
  vector<int> box(n, 1);
  vector<bool> red(n, false);
  red[0] = true;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    box[a]--; box[b]++;
    if (red[a]) red[b] = true;
    if (box[a] == 0) red[a] = false;
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (red[i]) cnt++;
  }

  cout << cnt << endl;
}
