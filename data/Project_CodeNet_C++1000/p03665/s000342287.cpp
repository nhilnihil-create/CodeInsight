#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 55;

ll choose [MAX_N][MAX_N];

int main () {
  choose[0][0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j < MAX_N; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  int n, p;
  cin >> n >> p;

  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x % 2 == 0) c0++;
    else c1++;
  }

  ll oddw = 0;
  for (int i = p; i <= c1; i += 2) {
    oddw += choose[c1][i];
  }

  ll ans = oddw * (1LL << c0);
  cout << ans << endl;
}
