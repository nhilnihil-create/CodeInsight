#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, l, r, G;
  G = 0;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int p = 0;
    cin >> l >> r;
    p = ((r - l) + 1);
    G += p;
  }
  cout << G << endl;

  return 0;
}