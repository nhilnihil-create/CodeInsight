#include <iostream>
#include <stdlib.h>
using namespace std;
#define REP(i, n) for (int i = 1; i <= (n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  int x[101];
  REP(i, N) cin >> x[i];

  int total = 0;
  REP(i, N) {
    int distA = x[i];
    int distB = abs(K - x[i]);
    total += distA < distB ? 2*distA : 2*distB;
  }
  cout << total << endl;

  return 0;
}