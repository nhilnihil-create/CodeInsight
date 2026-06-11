#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<LL>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  sort(A.begin(), A.end());
  vector<LL>sum(N + 1);
  sum[0] = A[0];
  for (int i = 1; i < N; i ++) sum[i] = sum[i - 1] + A[i];
  sum[N] = 1e16;
  int mi = 0;
  int ma = N - 1;
  while (mi != ma) {
    int mu = (ma + mi) / 2;
    LL now = A[mu];
    bool ok = true;
    while (now != sum[N - 1]) {
      int s = mu;
      int l = N;
      while (s != l) {
        int m = (s + l) / 2;
        if (A[m] > now * 2) l = m;
        else s = m + 1;
      }
      if (now == sum[l - 1]) {
        ok = false;
        break;
      }
      now = sum[l - 1];
    }
    if (ok) ma = mu;
    else mi = mu + 1;
  }
  cout << N - ma << endl;
}

