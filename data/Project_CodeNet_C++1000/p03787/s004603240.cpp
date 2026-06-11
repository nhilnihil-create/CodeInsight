#include <bits/stdc++.h>
using namespace std;

int N, M;
#define MAX_N 100000
vector<int> A[MAX_N];
int C[MAX_N];
long long S, O, X;

bool see(int v, int c) {
  bool res = false;
  C[v] = c;
  for(int w : A[v]) {
    if(!C[w]) res |= see(w, -c);
    else if(C[w] == c) res = true;
  }
  return res;
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v; --u; --v; A[u].push_back(v); A[v].push_back(u);
  }
  for(int v = 0; v < N; ++v) if(!C[v]) {
    if((int)A[v].size() == 0) ++S;
    else ++(see(v, 1) ? O : X);
  }
  cout << 2 * N * S - S * S + (O + X) * (O + X) + X * X << endl;
  return 0;
}
