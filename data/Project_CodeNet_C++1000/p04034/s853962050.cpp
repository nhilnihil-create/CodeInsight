#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<int> BOX(N, 1);
  vector<bool> RED(N, false);
  RED[0] = true;

  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if (RED[x]) RED[y] = true;
    BOX[x]--;
    BOX[y]++;
    if (BOX[x] == 0) RED[x] = false;
  }

  int64_t answer = 0;
  rep(i, N) {
    if (RED[i]) answer++;
  }
  cout << answer << endl;
  return 0;
}
