//実装できなくて答え見た
//きれいなコード
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  string s;
  vector<string> cand = {"dreamer", "eraser", "dream", "erase"};
  cin >> s;
  reverse(s.begin(), s.end());
  rep(i, 4) reverse(cand[i].begin(), cand[i].end());
 
  bool flag = true;
  while (flag) {
    flag = false;
    // cerr << s << endl;
    rep(i, 4) {
      if (s.substr(0, cand[i].size()) == cand[i]) {
        s.erase(0, cand[i].size());
        flag = true;
        break;
      }
    }
  }
  cout << (s.size() == 0 ? "YES" : "NO") << endl;
  return 0;
}