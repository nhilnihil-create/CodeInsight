#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100005;
int A[MAX_N], N;

int gcd(int x, int y) {
  return x == 0 ? y : gcd(y % x, x);
}

int work() {
  int even = 0, odd = 0;
  for (int i = 1; i <= N; ++i)
    if (A[i] & 1) odd++;
    else even++;
  if (even & 1)
    return 1;
  else if (!(even & 1) && odd > 1) 
    return 0;
  else {
    for (int i = 1; i <= N; ++i)
      if (A[i] & 1) {
	if (A[i] == 1) return 0;
	A[i]--;
	break;
      }
    int g = A[1];
    for (int i = 2; i <= N; ++i)
      g = gcd(g, A[i]);
    for (int i = 1; i <= N; ++i)
      A[i] /= g;
    return work() ^ 1;
  }
}

int main() {


  int T = 1;
  //scanf("%d", &T);
  
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
      scanf("%d", &A[i]);
    bool flag = work();
    if (flag)
      puts("First");
    else
      puts("Second");
  }
  
  return 0;
}
