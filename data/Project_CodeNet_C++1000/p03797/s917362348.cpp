#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, M; cin >> N >> M;
  
  if (M <= N * 2) { cout << M / 2 << endl; return 0; }
  
  int64_t tmp = (M - N * 2) / 4;
  
  cout << N + tmp << endl;
  
}