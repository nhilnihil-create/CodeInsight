#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  sort(A.begin(), A.end());
  int ans = 1;
  int now = 0;
  int ps = 1;
  for (int i = 1; i < N; i ++) {
    if (ps < C && (A[i] - A[now]) <= K) ps ++;
    else {
      now = i;
      ans ++;
      ps = 1;
    }
  }
  cout << ans << endl;
}