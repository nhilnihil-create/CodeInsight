#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<char> S(N);
    for (int i = 0; i < N; i++) {
      cin >>S.at(i);
    }
  
  int x = 0;
  
  vector<int> X(N+1);
  X.at(0) = 0;
  for (int i = 1; i < N+1; i++) {
    if (S.at(i-1) == 'I') {
      x++;
      X.at(i) = x;
    }
    else {
      x--;
      X.at(i) = x;
    }
  }
  sort(X.begin(), X.end());
  cout << X.at(N) << endl;
}