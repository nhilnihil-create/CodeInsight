#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int even = 0, odd = 0, four = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a%2 == 0) {
      even++;
      if (a%4 == 0) {
        four++;
      }
    }
  }
  odd = N - even;
  if (odd <= four || odd == four + 1 && even == four) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}