#include <iostream>
#include <string>

using namespace std;
typedef long long lint;

const int MAXN = 333;
lint D[MAXN][MAXN];
bool need[MAXN][MAXN];

lint solve(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      need[i][j] = true;
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (k == i || k == j) continue;
        if (D[i][j] == D[i][k] + D[k][j]) {
          need[i][j] = false;
        } else if (D[i][j] > D[i][k] + D[k][j]) {
          return -1;
        }
      }
    }
  }
  lint ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (need[i][j]) {
        ans += D[i][j];
      }
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> D[i][j];
    }
  }
  cout << solve(N) << endl;
  return 0;
}