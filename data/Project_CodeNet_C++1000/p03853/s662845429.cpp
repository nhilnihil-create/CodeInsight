#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> answer(2 * H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> answer[i * 2][j];
      answer[i * 2 + 1][j] = answer[i * 2][j];
    }
  }
  rep(i, 2 * H) {
    rep(j, W) { cout << answer[i][j]; }
    cout << endl;
  }
  return 0;
}