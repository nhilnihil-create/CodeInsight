#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  cin >> N;

  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  int i = 0;
  int ai = a.at(i);
  for (i = 0; i < N - 1; i++) {
    if (ai == 2) {
      break;
    }
    ai = a.at(ai - 1);
  }

  if (i < N - 1) {
    cout << i + 1 << endl;
  } else {
    cout << -1 << endl;
  }
}
