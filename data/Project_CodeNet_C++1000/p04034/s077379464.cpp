#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  int N, M, x, y, ans = 0;
  scanf("%d %d", &N, &M);
  int num_ball[N];
  bool has_ball[N];
  fill_n(num_ball, N, 1);
  fill_n(has_ball, N, false);
  has_ball[0] = 1;
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &x, &y);
    has_ball[y - 1] = has_ball[x - 1] || has_ball[y - 1];
    --num_ball[x - 1];
    ++num_ball[y - 1];
	if (num_ball[x - 1] == 0) has_ball[x - 1] = false;
  }
  for (int i = 0; i < N; ++i) {
    if (has_ball[i]) ++ans;
  }
  printf("%d", ans);
  return 0;
}