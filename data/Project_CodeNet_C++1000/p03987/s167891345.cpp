#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  
  set<int> s;
  vector< pair<int, int> > v;
  
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(make_pair(x, i));
  }
  
  sort(v.begin(), v.end());
  
  s.insert(-1);
  s.insert(N);
  
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    auto it = s.lower_bound(v[i].second);
    int r = *it;
    int l = *(--it);
    ans += (long long)(i + 1) * (v[i].second - l) * (r - v[i].second);
    s.insert(v[i].second);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}