#include <bits/stdc++.h>
using namespace std;

int N;
#define MAXN 100000
int A[MAXN];
vector<int> adj[MAXN];

long long dfs(int v, int par) {
  vector<long long> ns; long long sum_ns = 0;
  for(auto w : adj[v]) {
    if(w == par) continue;
    ns.push_back(dfs(w, v));
    if(ns.back() < 0) return -1;
    sum_ns += ns.back();
  }
  if(ns.empty()) return A[v];
  long long d = sum_ns - A[v], n = A[v] - d;
  if(d < 0 || n < 0) return -1;
  int nns = ns.size();
  if(par < 0 && nns > 1 && n > 0) return -1;
  sort(ns.begin(), ns.end(), greater<long long>());
  if((ns[0] <= sum_ns - ns[0] ? sum_ns / 2 : sum_ns - ns[0]) < d) return -1;
  return n;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < N - 1; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    adj[a].push_back(b); adj[b].push_back(a);
  }
  printf("%s\n", dfs(0, -1) >= 0 ? "YES" : "NO");
  return 0;
}
