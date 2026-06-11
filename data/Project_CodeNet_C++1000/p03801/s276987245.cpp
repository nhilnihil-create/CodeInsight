#include <bits/stdc++.h>

using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

const int N_ = int(1.1e5);

int N;
int A[N_];
pii B[N_], pref[N_];

long long ans[N_];

priority_queue<pll> pq;

int main() {
#ifdef IN_MY_COMPUTER
  freopen("e.in", "r", stdin);
#endif
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    B[i] = make_pair(A[i], i);
  }
  sort(B+1, B+N+1, greater<pii>());
  for(int i = 1; i <= N; i++) {
    pref[i] = max(pref[i-1], make_pair(A[i], -i));
  }
  for(int i = 1; i <= N; i++) {
    pref[i].second *= -1;
  }

  for(int i = N; i > 0; i--) {
    if(pref[i].second == i) {
      int cnt = 1;
      while(!pq.empty() && pq.top().first >= pref[i-1].first) {
        ans[i] += pq.top().second * (pq.top().first - pref[i-1].first);
        cnt += pq.top().second;
        pq.pop();
      }
      ans[i] += pref[i].first - pref[i-1].first;
      pq.emplace(pref[i-1].first, cnt);
    }else {
      pq.emplace(A[i], 1);
    }
  }
  
  for(int i = 1; i <= N; i++) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}