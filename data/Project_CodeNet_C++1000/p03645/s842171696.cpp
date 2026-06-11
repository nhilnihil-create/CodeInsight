#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N, M; cin >> N >> M;
  
  unordered_map<int,int> s, g;
  rep(i, M) {
    int a, b; cin >> a >> b;
    if(a == 1) s[b]++;
    if(b == N) g[a]++;
  }
  
  for(auto p : s) {
    if(g[p.first] > 0) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  
}
