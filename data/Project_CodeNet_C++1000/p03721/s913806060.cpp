#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, K; cin >> N >> K;
  map<int,int> m;
  rep(i, N) {
    int a, b; cin >> a >> b;
    m[a] += b;
  }
  for(auto p : m) {
    if(p.second >= K) {
      cout << p.first << endl;
      return 0;
    } else {
      K -= p.second;
    }
  }
  
}