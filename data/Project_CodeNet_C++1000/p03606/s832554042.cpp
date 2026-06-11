#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, l, r, X;
  cin >> N;
  X = 0;
  for (int i = 0; i < N; i++){
  cin >> l >> r;
  X = X + (r - l + 1);
  }
  cout << X << endl;
}
