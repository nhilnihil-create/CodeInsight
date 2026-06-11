#include <bits/stdc++.h>
using namespace std;
int main() {
  int W,H,N;
  cin >> W >> H >> N;
  vector<int>x(N);
  vector<int>y(N);
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }
  int minX = 0;
  int maxX = W;
  int minY = 0;
  int maxY = H;
  for (int i = 0; i < N; i++) {
    if (a.at(i) == 1){
      if (x.at(i) > minX){
        minX = x.at(i);
      }
    }
    else if (a.at(i) == 2){
      if (x.at(i) < maxX){
        maxX = x.at(i);
      }
    }
    else if (a.at(i) == 3){
      if (y.at(i) > minY){
        minY = y.at(i);
      }
    }
    else if (a.at(i) == 4){
      if (y.at(i) < maxY){
        maxY = y.at(i);
      }
    }
  }
  cout << max(maxX-minX,0) * max(maxY-minY,0) << endl;
}