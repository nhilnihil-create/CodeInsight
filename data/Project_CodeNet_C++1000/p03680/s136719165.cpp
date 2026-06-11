#include <bits/stdc++.h>
using namespace std;

int main () {
  int N, b, c, d;
  b = 1;
  c = 0;
  d = 1;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  while (b != 2) {
    b = a.at(d - 1);
    a.at(d - 1) = -1;
    d = b;
    c++;
    if (b == -1) {
      break;
    }
  }
  if (b == -1) {
    cout << b << endl;
  }
  else {
    cout << c << endl;
  }
}