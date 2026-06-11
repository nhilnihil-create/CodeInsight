#include <bits/stdc++.h>
using namespace std;

int main () {
  int N, b, c;
  b = 1;
  c = 0;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  while (b != 2) {
    b = a.at(b - 1);
    c++;
    if (c > N) {
      break;
    }
  }
  if (c > N) {
    cout << -1 << endl;
  }
  else {
    cout << c << endl;
  }
}