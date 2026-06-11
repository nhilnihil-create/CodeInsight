#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

char colors [4] = {'R', 'G', 'B', 'Y'};

int main () {
  ios::sync_with_stdio(false);

  int n, m, d;
  cin >> n >> m >> d;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int dd = ((MAX_N + i + j) / d) % 2;
      int ud = ((MAX_N + i - j) / d) % 2;
      cout << colors[dd + 2 * ud];
    }
    cout << '\n';
  }
}
