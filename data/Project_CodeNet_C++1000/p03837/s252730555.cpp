#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const int INF = 1005;
const int MAXN = 105;
const int MAXM = 1005;

int G[MAXN][MAXN];
int U[MAXM], V[MAXM], W[MAXM];

int main() {
  int n, m;
  cin >> n >> m;
    
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    U[i] = a, V[i] = b, W[i] = c;
    G[a][b] = G[b][a] = c;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        G[i][j] = 0;
      } else if (G[i][j] == 0) {
        G[i][j] = INF;
      }
    }
  }
  
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
      }
    }
  }
  
  int ans = m;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (G[i][U[j]] + W[j] == G[U[j]][V[j]]) {
        ans -= 1; 
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
