#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, a, b, now;
  scanf("%lld%lld", &n, &m);
  bool flg[n], t;
  vector<ll> vec[n];
  deque<ll> ans;
  for(i = 0; i < m; ++i) {
    scanf("%lld%lld", &a, &b);
    vec[--a].push_back(--b);
    vec[b].push_back(a);
  }
  ans.push_front(0);
  for(i = 0; i < n; ++i) flg[i] = true;
  flg[0] = false;
  while(1) {
    now = ans.front();
    t = false;
    for(i = 0; i < vec[now].size(); ++i) if(flg[vec[now][i]]) {
      ans.push_front(vec[now][i]);
      flg[vec[now][i]] = false;
      t = true;
      break;
    }
    if(t) continue;
    now = ans.back();
    for(i = 0; i < vec[now].size(); ++i) if(flg[vec[now][i]]) {
      ans.push_back(vec[now][i]);
      flg[vec[now][i]] = false;
      t = true;
      break;
    }
    if(t) continue;
    else break;
  }
  printf("%lld\n", ans.size());
  while(ans.size()) printf("%lld ", ans.front() + 1), ans.pop_front();
  return 0;
}