#include <bits/stdc++.h>
using namespace std;
int64_t MAXN = 15, INF = pow(10, 12), zero = 0;
int64_t N, K, ans = 0;
vector<int64_t> A(MAXN);

int64_t dfs(int64_t idx, int64_t cnt, int64_t cost, int64_t prevh)
{
  if (cnt == K)
    return cost;
  if (idx == N)
    return INF;
  if (A.at(idx) > prevh)
  {
    return dfs(idx + 1, cnt + 1, cost, A.at(idx));
  }
  int64_t a, b;
  a = dfs(idx + 1, cnt + 1, cost + (prevh - A.at(idx) + 1), prevh + 1);
  b = dfs(idx + 1, cnt, cost, prevh);
  return min(a, b);
}

int main()
{
  cin >> N >> K;
  for (int i = 0; i < N; i++)
    cin >> A.at(i);
  if (K != 1)
    ans = dfs(1, 1, 0, A.at(0));
  cout << ans << endl;
}