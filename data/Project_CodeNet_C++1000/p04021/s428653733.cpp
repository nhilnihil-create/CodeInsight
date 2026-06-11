#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair
#define CHECK(x) if(!(x)) return false;
#define CHECKRET(x, y) if(!(x)) return (y);
#define SKIP(x) if((x)) continue;
typedef pair<int, int> pii;

const int MAXN = 100010;
pii sorted[MAXN];

int fucked[2];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    sorted[i].second = i;
    scanf("%d", &sorted[i].first);
  }
  sort(sorted, sorted + N);
  for (int i = 0; i < N; ++i) {
    SKIP(sorted[i].second % 2 == i % 2);
    ++fucked[i % 2];
  }
  printf("%d\n", max(fucked[0], fucked[1]));
  return 0;
}
