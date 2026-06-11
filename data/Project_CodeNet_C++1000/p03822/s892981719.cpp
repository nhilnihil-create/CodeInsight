#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
typedef long long ll;
using namespace std;
vector<ll> vec[100000];

ll dfs(ll a) {
  ll ans = 1, cnt[vec[a].size()], i;
  for(i = 0; i < vec[a].size(); ++i) cnt[i] = dfs(vec[a][i]);
  sort(cnt, cnt + vec[a].size(), greater<ll>());
  for(i = 0; i < vec[a].size(); ++i) if(ans < i + cnt[i] + 1) ans = i + cnt[i] + 1;
  return ans;
}

int main(void) {
  ll i, j, n, a;
  scanf("%lld", &n);
  for(i = 1; i < n; ++i) scanf("%lld", &a), vec[--a].push_back(i);
  printf("%lld", dfs(0) - 1);
  return 0;
}