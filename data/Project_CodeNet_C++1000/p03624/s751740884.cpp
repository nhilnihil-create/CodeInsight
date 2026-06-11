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
  vector<int> v(26);
  rep(i,s.size()) v[s[i] - 'a']++;
  rep(i,26) {
    if (!v[i]) {
      cout << (char) ('a' + i) << endl;
      return;
    }
  }
  cout << "None" << endl;
}

int main() {
  solve();
  return 0;
}