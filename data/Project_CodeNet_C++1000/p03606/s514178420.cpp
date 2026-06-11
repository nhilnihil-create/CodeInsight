#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, V;
  cin >> N;
   A = 0;
  for (int i = 0; i < N; i++){
    int l, r, s;
    cin >> l >> r;
    s = r - l + 1;
    A = A + s;}
  cout << A << endl;
}
