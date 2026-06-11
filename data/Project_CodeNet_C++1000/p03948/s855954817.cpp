#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const int N_ = int(1.1e5);

int N, T;
int A[N_];

int pref[N_], suff[N_];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif
  scanf("%d%d", &N, &T);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  pref[1] = A[1];
  for(int i = 2; i <= N; i++) {
    pref[i] = min(pref[i-1], A[i]);
  }

  lint max_profit = 0;
  for(int i = 2; i <= N; i++) {
    lint cur_profit = (lint)(A[i] - pref[i-1]) * (T/2);
    max_profit = max(max_profit, cur_profit);
  }

  int ans = 0;
  for(int i = 2; i <= N; i++) {
    lint cur_profit = (lint)(A[i] - pref[i-1]) * (T/2);
    if(cur_profit == max_profit) {
      ans += 1;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}