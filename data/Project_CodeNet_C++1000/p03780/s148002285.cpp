#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<int> A;

bool need(int idx) {
  int a = A[idx];
  if (a >= K) return true;
  vector<int> dp(K+1);
  dp[0] = 1;
  int max_j = 0;
  for (int i = 0; i < N; i++) {
    if(i == idx) continue;
    int b = A[i];
    int max_j2 = max_j;
    for (int j = 0; j <= max_j; j++) {
      if (dp[j] == 0) continue;
      if (j+b < K-a) {
        dp[j+b] = 1;
        max_j2 = max(max_j2, j+b);
      } else if (j+b < K) {
        return true;
      }
    }
    max_j = max_j2;
  }
  return false;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(),A.end(),greater<int>());

  int ok = -1;
  int ng = N;
  while (ng - ok > 1) {
    int m = (ok+ng) / 2;
    if(need(m)) {
      ok = m;
    } else {
      ng = m;
    }
  }
  cout << N - ok - 1 << endl;
}