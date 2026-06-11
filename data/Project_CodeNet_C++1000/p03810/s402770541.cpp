#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, A[100005];

int work() {
  int even = 0, odd = 0, one = 0;
  for (int i = 1; i <= N; ++i)
    if (A[i] == 1) one++;
    else if (A[i] & 1) odd++;
    else even++;
  
  if (one) return even & 1;

  if (even & 1) return 1;

  if (!(even & 1) && odd >= 2) return 0;

  for (int i = 1; i <= N; ++i)
    if (A[i] & 1) A[i]--;
  int g = A[1];
  for (int i = 2; i <= N; ++i)
    g = __gcd(g, A[i]);
  for (int i = 1; i <= N; ++i)
    A[i] /= g;
  return work() ^ 1;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
  
  int res = work();

  if (res) puts("First");
  else puts("Second");
  
  return 0;
}
