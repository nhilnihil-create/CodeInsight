#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  int n, k;
  cin >> n >> k;
  int D[k];
  for (int i = 0; i < k; i++) cin >> D[i];

  int r[5]; int i = 0;
  int nn = n;
  while(true) {
    i = 0;
      while(nn>0) {
      r[i++] = nn % 10;
      nn /= 10;
    }
    int len = i, key = 0; 
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < k; j++) {
        if (D[j] == r[i]) {key = -1; break; }
      }
    }
    if (key == -1) {
      n++; nn = n;
    } else {
      cout << n << endl; break;
    }
  }
  
}