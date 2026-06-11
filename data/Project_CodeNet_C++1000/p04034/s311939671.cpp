#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int N, M;
  cin >> N >> M;

  int x[M];
  int y[M];
  for (int i = 0; i < M; ++i) {
    cin >> x[i];
    cin >> y[i];
    --x[i];
    --y[i];
  }

  int balls[N];
  int red_balles[N];
  for (int i = 0; i < N; ++i) {
    balls[i] = 1;
    red_balles[i] = 0;
  }
  red_balles[0] = 1;

  for (int i = 0; i < M; ++i) {
    if (red_balles[x[i]] > 0)
      red_balles[y[i]] = 1;
    --balls[x[i]];
    ++balls[y[i]];
    if (balls[x[i]] == 0)
      red_balles[x[i]] = 0;
  }

  long long ret = 0;
  for (int i = 0; i < N; ++i)
    if (red_balles[i] > 0)
      ++ret;

  cout << ret << endl;

  return 0;
}