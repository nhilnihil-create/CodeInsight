#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<pair<int, int>, int> cells;

int main() {
  int i;
  long long H, W, N;
  long long ans[10] = {};
  scanf("%lld %lld %lld", &H, &W, &N);
  int a[100010], b[100010];
  for (i = 0; i < N; i++) {
    scanf("%d %d", &a[i], &b[i]);
    a[i] -= 1;
    b[i] -= 1;
  }
  long long not_white = 0;
  for (i = 0; i < N; i++) {
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
	int X = a[i] + dx;
	int Y = b[i] + dy;
	if (X <= 0 || Y <= 0 || X >= H-1 || Y >= W-1) {
	  continue;
	}
	pair<int, int> P;
	P = make_pair(X, Y);
	if (cells.find(P) != cells.end()) {
	  cells[P] += 1;
	} else {
	  cells[P] = 1;
	  not_white += 1;
	}
      }
    }
  }

  ans[0] = (H-2)*(W-2) - not_white;
  for (auto x : cells) {
    int num = x.second;
    ans[num] += 1;
  }
  for (i = 0; i < 10; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
  
