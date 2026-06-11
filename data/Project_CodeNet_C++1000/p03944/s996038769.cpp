#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int Mx = 0, mx = W, My = 0, my = H;
  vector<int> x(N), y(N), a(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i) >> a.at(i);
    if (a.at(i) == 1) Mx = max(x.at(i), Mx);
    if (a.at(i) == 2) mx = min(x.at(i), mx);
    if (a.at(i) == 3) My = max(y.at(i), My);
    if (a.at(i) == 4) my = min(y.at(i), my);
  }
  
  int wide = max(0, mx - Mx), height = max(0, my - My);
  cout << wide * height << endl;
}
