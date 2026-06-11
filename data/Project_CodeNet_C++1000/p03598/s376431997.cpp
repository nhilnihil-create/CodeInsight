#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int A, B, S;
  A = 0; B = 0; S = 0; 
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A = x;
    B = abs(K - x);
    if (A <= B)
      S += A;
    else if (A > B)
      S += B;
  }   
      cout << 2 * S << endl;
}
