#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main() {
  int W,H,N;
  cin >> W >> H >> N;
  int up=H,dw=0,ri=W,le=0;
  int x,y,a;
  while(N--) {
    cin >> x >> y >> a;
    switch(a) {
      case 1: le = max(le, x); break;
      case 2: ri = min(ri, x); break;
      case 3: dw = max(dw, y); break;
      case 4: up = min(up, y); break;
      default: break;
    }
  }
  //printf("%d %d %d %d\n", up, dw, ri, le);
  cout << max((ri-le),0) * max((up-dw),0) << endl;
  return 0;
}
