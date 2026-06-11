#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

const int N_MAX = 2010;
vector<int> adj[N_MAX];
int d[N_MAX][N_MAX];

void dfs(int from, int n, int p) {
  for (auto x: adj[n]) {
    if (x!=p) {
      d[from][x] = d[from][n]+1;
      dfs(from,x,n);
    }
  }
}

int main() {
  int N, K; cin >> N >> K;
  rep(i,N-1) {
    int A, B; cin >> A >> B; A--; B--;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  rep(i,N) {
    fill_n(d[i],N,-1); d[i][i] = 0;
    dfs(i,i,-1);
  }
  ll result = INF;
  rep(i,N) {
    if (K%2==0) {
      ll tmp = 0;
      rep(j,N) if (d[i][j]>K/2) tmp++;
      result = min(result, tmp);
    }
    else for (auto j: adj[i]) {
      ll tmp = 0;
      rep(k,N) if (min(d[i][k],d[j][k])>K/2) tmp++;
      result = min(result, tmp);
    }
  }
  cout << result << endl;
  return 0;
}