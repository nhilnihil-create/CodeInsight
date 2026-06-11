#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, l, r;
  int x = 0;
  cin >> N;
  for (int j = 0; j < N; j++) {
    cin >> l >> r;
    x += r - l + 1;}
  cout << x << endl;
}