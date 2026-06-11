#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main () {
  int N; cin >> N;
  int d = 2;
  int max = 0;

  while (true) {
    if (N >= d) {
      max = d;
      d *= 2;
    } else if (N <= 2) {
      max = 1;
      break;
    } else {
      break;
    }
  }

  cout << max << endl;

  return 0;
}
