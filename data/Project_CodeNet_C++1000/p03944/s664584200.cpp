#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int w,h,n,x[200],y[200],a[200];
  cin >> w >> h >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> a[i];
  
  int s = 0, t = 0;
  int u = w, v = h;
  for(int i = 0; i < n; i++) {
    if(a[i] == 1) {
      if(u <= x[i]) {
        cout << "0" << endl;
        return 0;
      }
      if(s < x[i]) s = x[i];
    }
    if(a[i] == 2) {
      if(s >= x[i]) {
        cout << "0" << endl;
        return 0;
      }
      if(u > x[i]) u = x[i];
    }
    if(a[i] == 3) {
      if(v <= y[i]) {
        cout << "0" << endl;
        return 0;
      }
      if(t < y[i]) t = y[i];
    }
    if(a[i] == 4) {
      if(t >= y[i]) {
        cout << "0" << endl;
        return 0;
      }
      if(v > y[i]) v = y[i];    
    }
  }
  cout << (u-s)*(v-t) << endl;
}
