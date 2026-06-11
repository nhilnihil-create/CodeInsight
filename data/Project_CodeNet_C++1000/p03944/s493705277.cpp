#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int W, H, N;
  cin >> W >> H >> N;
  int xl = 0;
  int xr = W;
  int yl = 0;
  int yr = H;
  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    switch (a) {
      case 1:
        xl = max(xl, x); break;
      case 2:
        xr = min(xr, x); break;
      case 3:
        yl = max(yl, y); break;
      case 4:
        yr = min(yr, y); break;
    }
  }
  cout << max(0,(xr-xl))*max(0,(yr-yl)) << endl;
  return 0;
}
