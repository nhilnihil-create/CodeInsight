#include <bits/stdc++.h>
using namespace std;

int main() {
  string A; cin >> A;
  long long N = A.size();
  long long ans = N * (N - 1) / 2 + 1;
  map<int, long long> M;
  for (int i = 0; i < N; i++) {
    int idx = A.at(i) - 'a';
    if (M.count(idx)) M[idx]++;
    else M[idx] = 1;
  }
  for (int i = 0; i < 26; i++) {
    if (M.count(i)) ans -= M[i] * (M[i] - 1) / 2; 
  }
  cout << ans << endl;
}