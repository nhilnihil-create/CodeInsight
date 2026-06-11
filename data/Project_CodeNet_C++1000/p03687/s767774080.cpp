#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s; cin >> s;
  int l = s.size();

  int cnt = 0;
  //char c = 'a';
  vector<int> cum;
  rep(i,26) {
    char cc = 'a' + i;
    int cnt = 0, ans = -1;
    rep(j,l) {
      if (s[j] != cc) cnt++;
      else {ans = max(ans, cnt); cnt = 0;}
    }
    ans = max(ans, cnt); 
    cum.push_back(ans);
  }
  cout << *min_element(cum.begin(), cum.end()) << endl;
  return 0;
}