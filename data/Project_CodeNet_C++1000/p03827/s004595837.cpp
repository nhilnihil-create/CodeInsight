#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, x = 0, y = 0;
  string S;
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'I') {x++;}
    else {x--;}
    y = max(y, x);
  }
  cout << y << endl;
}