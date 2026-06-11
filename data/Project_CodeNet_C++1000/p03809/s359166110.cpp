#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<vector<ll>> adj;
vector<ll> to_p;
vector<ll> A;

bool dfs(int n, int p=-1) {
  ll tmp = 0, mtmp = 0;
  for (auto x: adj[n]) {
    if (x==p) continue;
    if (!dfs(x,n)) return false;
    tmp += to_p[x];
    mtmp = max(mtmp, to_p[x]);
  }
  if (tmp!=0&&A[n]>tmp) return false;
  if (mtmp>A[n]) return false;
  to_p[n] = (adj[n].size()==1) ? A[n]-tmp : A[n]*2-tmp;
  // cout << n << " " << p << " " << to_p[n] << " " << mtmp << endl;
  return to_p[n]>=0;
}

int main() {
  int N; cin >> N;
  A.resize(N); rep(i,N) cin >> A[i];
  adj.resize(N); to_p.resize(N);
  rep(i,N-1) {
    ll a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  string result = (dfs(0)&&to_p[0]==0) ? "YES" : "NO";
  cout << result << endl;
  return 0;
}