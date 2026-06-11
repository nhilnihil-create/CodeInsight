#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<bool> red(N, 0);
  red.at(0) = 1;
  vector<int> ball(N, 1);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ball.at(x)--;
    ball.at(y)++;
    if (red.at(x)) red.at(y) = 1;
    if (!ball.at(x)) red.at(x) = 0;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (red.at(i) && ball.at(i) > 0) ans++;
  }
  cout << ans << endl;
}
