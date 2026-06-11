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
  vector<int> v(4);
  rep(i,s.size()) {
    if (s[i] == 'N') v[0]++;
    else if (s[i] == 'S') v[1]++;
    else if (s[i] == 'E') v[2]++;
    else v[3]++;
  }
  bool b = true;
  rep(i,4) {
    if (!v[i]) b = false;
  }
  if (v[0] && v[1] && !v[2] && !v[3]) b = true;
  if (!v[0] && !v[1] && v[2] && v[3]) b = true;
  cout << (b? "Yes": "No") << endl;
}

int main() {
  solve();
  return 0;
}