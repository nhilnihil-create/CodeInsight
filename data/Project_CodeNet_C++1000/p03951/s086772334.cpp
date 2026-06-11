#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  string s, t; cin >> s >> t;
  
  int k = N-1;
  while(k >= 0 && s.substr(N-1-k) != t.substr(0,k+1)) k--;
  
  cout << 2*N-k-1 << endl;
}
