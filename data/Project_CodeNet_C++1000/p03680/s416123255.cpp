#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> button(N);
  for (int i = 0; i < N; i++) {
    cin >> button.at(i);
  }
  int A = 1, C = 0;
  for (int i = 0; i < N; i++) {
    A = button.at(A - 1);
    C++;
    if (A == 2) {
      cout << C << endl;
      break;
    }
  }
  if (C == N) {
    cout << "-1" << endl;
  }
}