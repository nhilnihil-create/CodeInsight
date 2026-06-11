#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = INF;
  string y = "";
  rep(i,n) y = y + s[0];
  if (y == s) {
    cout << 0 << endl;
    return;
  }
  rep(i,n) {
    char c = s[i];
    int cnt = 0;
    string t = s;
    for(;;) {
      cnt++;
      string temp = "";
      string x = "";
      rep(j,t.size()-1) {
        if (t[j] == c || t[j+1] == c) temp = temp + c;
        else temp = temp + t[j];
        x = x + c;
      }
      if (x == temp) break;
      t = temp;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}