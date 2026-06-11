#include <iostream>
using namespace std;
using ll = long long;

ll d[300][300];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> d[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bool need = true;
      for (int k = 0; k < N; k++) if(k != i && k != j) {
        if (d[i][k] + d[k][j] == d[i][j]) {
          need = false;
          break;
        }
      }
      if (need) {
        res += d[i][j];
      }
    }
  }
  cout << res / 2 << endl;
  return 0;
}
