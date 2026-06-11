#include <bits/stdc++.h>

typedef long long Int;

using namespace std;

int main()
{
  int N;
  int a[300000];
  Int L[100001], R[100001];
  scanf("%d", &N);
  
  for (int i = 0; i < 3 * N; i++) {
    scanf("%d", &a[i]);
  }
  
  Int tot = 0;
  Int tot2 = 0;
  priority_queue<Int, vector<Int>, greater<Int>> pq;
  for (int i = 0; i < 2 * N; i++) {
    tot += a[i];
    pq.push(a[i]);
    if (pq.size() > N) {
      tot2 += pq.top(); pq.pop();
    }
    if (pq.size() == N) L[i - N + 1] = tot - tot2;
  }
  
  tot = 0;
  tot2 = 0;
  priority_queue<Int> pq2;
  for (int i = 3 * N - 1; i >= N; i--) {
    tot += a[i];
    pq2.push(a[i]);
    if (pq2.size() > N) {
      tot2 += pq2.top(); pq2.pop();
    }
    if (pq2.size() == N) R[2 * N - i] = tot - tot2;
  }
  
  Int ans = L[0] - R[N];
  for (int i = 1; i <= N; i++) {
    ans = max(ans, L[i] - R[N - i]);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}