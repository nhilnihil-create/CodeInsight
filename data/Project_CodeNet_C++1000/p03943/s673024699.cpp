#include <bits/stdc++.h>
using namespace std;

int main() {
  int d[3];
  cin >> d[0] >> d[1] >> d[2];
  for (int i=0; i<(1<<3); ++i) {
    int p,q;
    p = q = 0;
    for (int j=0; j<3; ++j) {
      if ((i >> j) & 1) {
        p += d[j];
      } else 
        q += d[j];
    }
    if (p==q){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}