#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  for (int i = 0; i < N; i++) {
    if (i % 2) continue;
    cout << S.at(i);
  }
  cout << "\n";
}