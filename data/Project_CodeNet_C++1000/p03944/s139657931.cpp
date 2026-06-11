#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  
  vector<int> X(N);
  vector<int> Y(N);
  vector<int> A(N);
  
  for (int i = 0; i < N; ++i) cin >> X.at(i) >> Y.at(i) >> A.at(i);
  
  int Xl = 0;
  int Xr = W;
  int Yu = H;
  int Yd = 0;
  
  for (int i = 0; i < N; ++i) {
    switch (A.at(i)) {
      case 1:
        if (Xl < X.at(i)) Xl = X.at(i);
        break;
      case 2:
        if (Xr > X.at(i)) Xr = X.at(i);
        break;
      case 3:
        if (Yd < Y.at(i)) Yd = Y.at(i);
        break;
      case 4:
        if (Yu > Y.at(i)) Yu = Y.at(i);
        break;
    }
  }
  if (Xl > Xr || Yd > Yu) {
    cout << 0 << endl;
  }
  else {
    cout << (Xr -Xl) * (Yu - Yd)  << endl;
  }
  
}