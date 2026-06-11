#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = N - 1; i >= 0; i -= 2) {
    cout << A.at(i) << " ";
  }
  if (N % 2 == 0) {
    for (int i = 0; i < N; i += 2) {
      cout << A.at(i) << " ";
    }
  }
  else {
    for (int i = 1; i < N; i += 2) {
      cout << A.at(i) << " ";
    }
  }
  cout << endl;
}