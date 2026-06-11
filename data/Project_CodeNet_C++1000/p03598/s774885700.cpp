#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  int K;

  cin >> N >> K;

  int i = 0;
  int D = 0;

  // Balls
  for (i = 0 ; i < N ; i++) {
    int x;
    cin >> x;

    // Type A
    int AD = x * 2;

    // Type B
    int BD = (K - x) * 2;

    if (AD > BD) {
      D += BD;
    } else {
      D += AD;
    }
  }

  cout << D << endl;

}
