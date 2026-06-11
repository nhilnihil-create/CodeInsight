#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int x[100010], y[100010];
int num[100010]; 
int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m) {cin >> x[i] >> y[i]; x[i]--; y[i]--;}
  vector<bool> red(n,false);
  red[0] = true;
  rep(i,n) num[i] = 1;
  rep(i,m) {
    if (red[x[i]]) red[y[i]] = true;
    num[x[i]]--; num[y[i]]++;
    if (num[x[i]] == 0) red[x[i]] = false;
  }
  int ans = 0;
  rep(i,n) {
    if (red[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}