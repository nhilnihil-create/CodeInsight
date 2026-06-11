#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <utility>

int n; int A[100005], cnt[100005];
inline bool check() {
  if(A[n] != A[n - 1]) return false;
  int half = (A[n] + 1) / 2;
  if(A[1] < half) return false;
  for(int i = half + 1; i <= A[n]; i ++) {
    if(cnt[i] < 2) return false;
  }
  if(A[n] & 1) {
    if(cnt[half] != 2) return false;
  } else {
    if(cnt[half] != 1) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++) scanf("%d", &A[i]), cnt[A[i]] ++;
  std::sort(A + 1, A + 1 + n);
  if(check()) {
    puts("Possible");
  } else {
    puts("Impossible");
  }
  return 0;
}