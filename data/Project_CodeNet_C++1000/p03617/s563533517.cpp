#include <bits/stdc++.h>
using namespace std;

int main() {
  long long Q,H,S,D,N;
  cin >> Q >> H >> S >> D >> N;
  
  long long A = min(Q*4, H*2);
  A = min(A, S);
  
  if (A*2 >= D){
    cout << (N/2)*D + (N % 2)*A << endl;
  }
  else {
    cout << A*N << endl;
  }
}

