#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N+1);
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i+1);
  }
  
  int p = 1;
  int r = 0;
  
  while (p != 2) {
    if (r > N - 1) {
      r = -1;
      break;
    }
    p = A.at(p);
    r += 1;
  }
  
  cout << r << endl;
}