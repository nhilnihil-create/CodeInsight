#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> A(H);
  map<char, int> cnt;
  for (int i = 0; i < H; i++) {
    cin >> A[i];
    for (int j = 0; j < W; j++) {
      cnt[A[i][j]]++;
    }
  }

  int group4 = (H / 2) * (W / 2), group2 = 0, group1 = 0;
  if (H % 2 == 0 || W % 2 == 0) {
    if (!(H % 2 == 0 && W % 2 == 0)) {
      group2 = (H % 2 == 0 ? H : W) / 2;
    }
  } else {
    group1 = 1;
    group2 = (H / 2) + (W / 2);
  }
  for (int i = 'a'; i <= 'z'; i++) {
    while (group4 > 0 && cnt[i] >= 4) {
      cnt[i] -= 4;
      group4--;
    }
    while (group2 > 0 && cnt[i] >= 2) {
      cnt[i] -= 2;
      group2--;
    }
    while (group1 > 0 && cnt[i] >= 1) {
      cnt[i] -= 1;
      group1--;
    }
    if (cnt[i] > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}