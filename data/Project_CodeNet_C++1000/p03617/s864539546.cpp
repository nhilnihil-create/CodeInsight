#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
  
  Q *= 4; H *= 2;
  
  int64_t minL = min(Q, min(H, S));
  
  int64_t withD = N / 2 * D + N % 2 * minL;
  
  int64_t withoutD = N * minL;
  
  cout << min(withD, withoutD) << endl;
  
}