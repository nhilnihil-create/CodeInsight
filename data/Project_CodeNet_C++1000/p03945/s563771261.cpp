#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s;
  cin >> s;
  int n = s.size();

 
  int ans = 0;
  char t = s[0];
  int cnt = 0;
  rep(i,n) {
    if (s[i] == t) cnt++;
    else {
      ans++; t = s[i];
    }
  }
  cout << ans << endl;
  return 0;
}