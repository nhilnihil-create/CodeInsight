#include <cstdio>
#include <list>
#include <vector>
 
typedef long long i64;
 
i64 n;
 
std::list<int> a;
std::vector<int> b;
 
int main() 
{
  scanf("%lld", &n);
  ++n;
  int tot = 1;
  a.push_back(1);
  b.push_back(1);
  for (int i = 62 - __builtin_clzll(n); i >= 0; --i) {
    if (n >> i & 1) {
      ++tot;
      a.push_front(tot);
      b.push_back(tot);
    }
    if (i)
{
      ++tot;
      a.push_back(tot);
      b.push_back(tot);
    }
  }
  std::vector<int> ans(a.begin(), a.end());
  for (int i = 0; i < b.size(); ++i) ans.push_back(b[i]);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}