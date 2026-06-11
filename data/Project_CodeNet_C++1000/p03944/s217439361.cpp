#include <bits/stdc++.h>
using namespace std;
int main() {
  int w,h,n;
  cin >> w >> h >> n;
  int a,b,c;
  int x=0,y=0;
  for (int i=0; i<n; i++) {
    cin >> a >> b >> c;
    switch (c) {
      case 1:
         if (x < a) {
           x = a;
         }
        break;
      case 2:
        if (w > a) {
          w = a;
        }
        break;
      case 3:
        if (y < b) {
          y = b;
        }
        break;
      case 4:
        if (h > b) {
          h = b;
        }
    }
  }
  if (x >= w || y >= h) {
    cout << 0 << endl;
  } else {
    cout << (w-x)*(h-y) << endl;
  }
}