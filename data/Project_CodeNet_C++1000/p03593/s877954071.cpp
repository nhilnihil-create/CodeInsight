#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int H, W;
bool solve(vector<int> A) {
  int g = 0, k = 0;
  if (W % 2 == 1) k += H / 2;
  if (H % 2 == 1) k += W / 2;
  if (W % 2 == 1 && H % 2 == 1) {
    g = 1;
  }
  int l = (H * W - 2 * k - g) / 4;
  for (int c = 0; l--;) {
    while (c < 26 && A[c] < 4) ++c;
    if (c == 26) return 0;
    A[c] -= 4;
  }
  for (int c = 0; k--;) {
    while (c < 26 && A[c] < 2) ++c;
    if (c == 26) return 0;
    A[c] -= 2;
  }
  return 1;
}
int main() {
  cin >> H >> W;
  vector<int> A(50);
  REP(i, H) REP(j, W) {
    char c;
    cin >> c;
    A[c - 'a']++;
  }
  printf("%s\n", solve(A) ? "Yes" : "No");
}