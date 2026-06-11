#include <bits/stdc++.h>

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

using namespace std;

const int N = 1000;
const int M = 2000;

struct Edge {
  int u, v, w;
}e[M];

ll d[N];
bool neg[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[i].u = u-1;
    e[i].v = v-1;
    e[i].w = w;
  }
  for (int i=0; i<n; i++) {
    d[i] = -LINF; 
    neg[i] =false;
  }
  d[0] = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<m; j++) {
      int u = e[j].u, v=e[j].v, w=e[j].w;
      if (d[u] + w > d[v]) d[v] = d[u] + w;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      int u = e[j].u, v=e[j].v, w=e[j].w;
      if (d[u] + w > d[v]) {
        d[v] = d[u] + w;
        neg[v] = true;
      }
    }
  }
  if (neg[n-1]) {
    cout << "inf" << endl;
    return 0;
  }
  cout << d[n-1] << endl;
  return 0;
}
