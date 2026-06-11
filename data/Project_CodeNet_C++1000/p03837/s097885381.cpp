#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct edge {
  int i, j, w;
};

int main() {
  int n, m;

  cin >> n >> m;

  vector< vector<int> > d(n, vector<int>(n, 1001));

  vector<edge> es(m);

  rep(i, m) {
    cin >> es[i].i >> es[i].j >> es[i].w;
  }


  for (auto ee = es.begin(); ee != es.end(); ee++) {
    edge e = *ee;

    d[e.i - 1][e.j - 1] = e.w;
    d[e.j - 1][e.i - 1] = e.w;
  }

  rep(k, n) {
    rep(i, n) {
      rep(j, n) {
        int l = d[i][k] + d[k][j];
        if (d[i][j] > l) {
          d[i][j] = l;
        }
      }
    }
  }


  int c = 0;

  for (auto ee = es.begin(); ee != es.end(); ee++) {
    edge e = *ee;
    if (d[e.i - 1][e.j - 1] < e.w) {
      c++;
    }
  }

  cout << c << endl;
}