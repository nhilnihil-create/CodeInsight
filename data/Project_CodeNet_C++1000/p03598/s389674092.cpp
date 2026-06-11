#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int K;
  int A = 0;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x; 
    if (K - x > x) {
      A = A + x * 2;
    }
    else {
      A = A + (K - x) * 2;
    }
  }
  cout << A << endl;
}
      