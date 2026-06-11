#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<vector<ll>> adj;
int dfs(int n=0, int p=-1) {
  int result = 0;
  for (auto x: adj[n]) {
    if (x==p) continue;
    result ^= dfs(x,n);
  }
  if (p!=-1) result++;
  // cout << n << " " << p << " " << result << endl;
  return result;
}

int main() {
  int N; cin >> N;
  adj.resize(N);
  rep(i,N-1) {
    ll x, y; cin >> x >> y; x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  string result = dfs() ? "Alice" : "Bob";
  cout << result << endl;
  return 0;
}