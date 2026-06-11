#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int N, M; cin >> N >> M;
  vector<int> vec(N+1, 0);
  rep(i, M) {
    int a, b; cin >> a >> b;
    vec[a]++; vec[b]++;
  }

  rep(i, N+1) {
    if(vec[i]%2 == 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

}
