#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  int h, w, n; cin >> h >> w >> n;
  queue<int> q;
  for (int i=0; i<n; i++){
    int a; cin >> a;
    rep(j, a) q.push(i+1);
  }

  vector<vector<int>> g(h, vector<int>(w));
  for (int i=0; i<h; i++) {
    if (i%2 == 0) {
      for (int j=0; j<w; j++) {
        g[i][j] = q.front(); q.pop();
      }
    } else {
      for (int j=w-1; j>=0; j--) {
        g[i][j] = q.front(); q.pop();
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (j>0) cout << " ";
      cout << g[i][j];
    }
    cout << endl;
  }

  return 0;
}
