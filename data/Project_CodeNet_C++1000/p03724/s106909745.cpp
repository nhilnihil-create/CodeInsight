#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N, M;
  cin >> N >> M;
  map<int, int> mp;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    mp[a]++;
    mp[b]++;
  }

  bool flag = true;
  for (int i = 0; i < N; i++) {
    if (mp[i] % 2 == 1) {
      flag = false;
      break;
    }
  }

  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}