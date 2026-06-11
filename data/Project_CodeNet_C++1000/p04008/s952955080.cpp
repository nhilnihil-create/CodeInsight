#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<vector<int>> adj;
vector<int> d;

int N, K;
ll result = 0;

int dfs(int n=0) {
  if (d[n]!=-1) return d[n];
  if (adj[n].size()==0) return d[n]=0;
  int r = -1;
  for (auto x: adj[n]) {
    if (n!=0&&dfs(x)==K-1) { result++; continue; }
    r = max(r, dfs(x));
  }
  r++;
  return d[n] = r;
}

int main() {
  cin >> N >> K;
  adj.resize(N, vector<int>{});
  d.resize(N, -1);

  rep(i,N) {
    int a; cin >> a; a--;
    if (i==0) { if (a!=0) result++; continue; }
    adj[a].push_back(i);
  }
  dfs();
  // rep(i,N) cout << d[i] << " "; cout << endl;
  cout << result << endl;
  return 0;
}