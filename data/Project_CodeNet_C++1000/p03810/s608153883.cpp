#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
  
int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

int solve() {
  for (int c = 0; ; c ^= 1) {
    int odd = 0;
    for (int i = 0; i < N; i++)
      odd += a[i] % 2;
    if ((N - odd) % 2)
      return c;
    if (odd != 1)
      return c ^ 1;
    for (int i = 0; i < N; i++)
      if (a[i] == 1)
        return c ^ 1;
    int g = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] % 2)
        a[i]--;
      g = __gcd(g, a[i]);
    }
    for (int i = 0; i < N; i++)
      a[i] /= g;
  }
}

int main() {
  load();
  puts(solve() ? "Second" : "First");
  return 0;
}