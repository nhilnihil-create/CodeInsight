#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m),c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i], --a[i], --b[i];
  vector<vector<int>> d(n,vector<int>(n,1e9));
  rep(i,n) d[i][i] = 0;
  rep(i,m) d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
  rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
  int ans = 0;
  rep(i,m) if(d[a[i]][b[i]]<c[i]) ++ans;
  cout << ans << endl;
}