#include <iostream>

using namespace std;

// const int MAX_N = 1000;

typedef long long ll;

/*
bool wins [MAX_N][MAX_N];

void calc_wins (int a, int b) {
  wins[a][b] = 0;
  for (int t = 2; t <= a; t += 2) {
    if (!wins[a - t][b + t / 2]) wins[a][b] = 1;
  }
  for (int t = 2; t <= b; t += 2) {
    if (!wins[a + t / 2][b - t]) wins[a][b] = 1;
  }
}
*/

int main () {
  /*
  for (int i = 0; i < 300; i++) {
    for (int a = 0; a <= i; a++) {
      calc_wins(a, i - a);
    }
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cout << (wins[i][j] ? '#' : '.');
    }
    cout << endl;
  }
  */

  ll a, b;
  cin >> a >> b;

  if (abs(a - b) <= 1) {
    cout << "Brown" << '\n';
  } else {
    cout << "Alice" << '\n';
  }
}
