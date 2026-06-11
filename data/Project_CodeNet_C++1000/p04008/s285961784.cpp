#include <bits/stdc++.h>
using namespace std;

int N, K;
#define MAX_N 100000
int P[MAX_N]; vector<int> C[MAX_N];
int D[MAX_N];
set<pair<int, int>> S;
int R;

void see(int v, int d) {
  D[v] = d;
  for(int w : C[v]) see(w, d + 1);
}
void erase(int v, int d) {
  S.erase({D[v], v});
  if(d == 0) return;
  for(int w : C[v]) erase(w, d - 1);
}
int main() {
  cin >> N >> K;
  for(int v = 0; v < N; ++v) {
    int a; cin >> a; --a; P[v] = a; if(v != 0) C[a].push_back(v);
  }
  see(0, 0);
  if(P[0] != 0) ++R;
  for(int v = 0; v < N; ++v) if(D[v] > K) S.insert({D[v], v});
  while(!S.empty()) {
    int v = S.rbegin()->second;
    for(int i = 0; i < K - 1; ++i) v = P[v];
    ++R; erase(v, K - 1);
  }
  cout << R << endl;
  return 0;
}
