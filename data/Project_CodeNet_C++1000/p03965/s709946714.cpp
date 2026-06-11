#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size(), P = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'p') P++;
  }
  cout << N / 2 - P << endl;
}