#include <algorithm>
#include <iostream>

using namespace std;

#define ALL(x) begin(x), end(x)


int main() {
  int W, H, N;
  cin >> W >> H >> N;

  int xmin{0},xmax{W},ymin{0},ymax{H};
  int x,y,a;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> a;
    switch(a) {
      case 1:
        xmin = max(xmin,x);
        break;
      case 2:
        xmax = min(xmax,x);
        break;
      case 3:
        ymin = max(ymin,y);
        break;
      case 4:
        ymax = min(ymax,y);
        break;
    }
  }

  cout << max(0,ymax-ymin)*max(0,xmax-xmin) << endl;

  return 0;
}
