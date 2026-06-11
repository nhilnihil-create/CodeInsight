#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int main() {
//  freopen("test.in", "r", stdin);
//  freopen("test.out", "w", stdout);
  
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(m);
  for (int i = 0; i < m; ++i)
    scanf("%d", &a[i]);
  int cnt = 0;
  for (int i = 0; i < m; ++i)
    cnt += a[i] & 1;
  if (cnt > 2) {
    puts("Impossible");
    return 0;
  }
  if (cnt)
    for (int i = 0; i < m; ++i)
      if (a[i] & 1) {
        swap(a[i], a[0]);
        break;
      }
  if (cnt == 2)
    for (int i = 1; i < m; ++i)
      if (a[i] & 1) {
        swap(a[i], a[m - 1]);
        break;
      }
  vector<int> ans;
  if (cnt == 0) {
    ans = a;
    --ans[0];
    ans.push_back(1);
  } else if (cnt == 1) {
    ans = a;
    ans.push_back(1);
    if (--ans.front() == 0)
      ans.erase(ans.begin(), ans.begin() + 1);
  } else {
    ans = a;
    ++ans[0];
    if (--ans.back() == 0)
      ans.pop_back();
  }
  for (int i = 0; i < m; ++i)
    printf("%d ", a[i]);
  printf("\n%lu\n", ans.size());
  for (int x : ans)
    printf("%d ", x);
  
  return 0;
}

