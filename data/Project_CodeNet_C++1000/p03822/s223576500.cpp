#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

const int N_MAX = pow(10,5);
vector<int> adj[N_MAX+10];
vector<int> d(N_MAX+10, -1);

int dfs(int n=0, int p=-1) {
  if (d[n]!=-1) return d[n];
  if (p!=-1&&adj[n].size()==1) return d[n] = 0;
  multiset<int, greater<int>> pos;
  for (auto x: adj[n]) {
    if (x!=p) pos.insert(dfs(x,n));
  }
  int result = 0, count = 1;
  for (auto x: pos) {
    result = max(result, x+count);
    count++;
  }
  return d[n] = result;
}

int main() {
  int N; cin >> N;
  rep(i,N-1) {
    int a; cin >> a; a--;
    adj[i+1].push_back(a);
    adj[a].push_back(i+1);
  }
  dfs();
  int result = 0;
  rep(i,N) result = max(result, d[i]);
  cout << result << endl;
  // rep(i,N) cout << d[i] << " "; cout <<  endl;
  return 0;
}