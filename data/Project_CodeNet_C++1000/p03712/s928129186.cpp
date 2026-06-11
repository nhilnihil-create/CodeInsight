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
  vector<vector<char>> MAP(H + 2, vector<char>(W + 2, '#'));
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      cin >> MAP[i][j];
    }
  }
  for (int i = 0; i < H + 2; i++) {
    for (int j = 0; j < W + 2; j++) {
      cout << MAP[i][j];
    }
    cout << endl;
  }
  return 0;
}