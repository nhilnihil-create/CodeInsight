#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 510;
int pnt[N], ans[N * N], ost[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> srt;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pnt[i] = x;
    srt.pb({x, i});
  }  
  sort(all(srt));
  set<int> empt;
  for (int i = 1; i <= n * n; i++) {
    empt.insert(i);
  }
  for (auto it : srt) {
    for (int j = 0; j < it.S - 1; j++) {
      if (empt.empty()) {
        cout << "No\n";
        exit(0);
      }
      if (*empt.begin() >= it.F) {
        cout << "No\n";
        exit(0);
      }
      ans[*empt.begin()] = it.S;
      empt.erase(empt.begin());
    }
    ans[it.F] = it.S;
    empt.erase(it.F);
    ost[it.S] = n - it.S;
  }
  for (auto it : empt) {
    int id = -1;
    for (int i = 1; i <= n; i++) {
      if (pnt[i] < it && ost[i] > 0) {
        id = i;
        break;
      }
    }
    if (id == -1) {
      cout << "No\n";
      exit(0);
    }
    ans[it] = id;
    ost[id]--;
  }
  cout << "Yes\n";
  for (int i = 1; i <= n * n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
} 