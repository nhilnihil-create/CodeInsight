#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M;
  char c;
  int A[55][55];
  int B[55][55];
  cin >> N >> M;
  rep(i, N) {
    rep(j, N) {
      cin >> c;
      if (c == '#') A[i][j] = 0;
      else A[i][j] = 1;
    }
  }
  rep(i, M) {
    rep(j, M) {
      cin >> c;
      if (c == '#') B[i][j] = 0;
      else B[i][j] = 1;
    }
  }
  rep(i, N-M+1) {
    rep(j, N-M+1) {
      int k,l;
      bool f = true;
      for(k=0; k < M; k++) {
        for (l=0; l < M; l++) {
          if (A[i+k][j+l] != B[k][l]) {f=false;break;}
        }
        if (!f) break;
      }
      //cout << k << " " << l << endl;
      if (f) {cout << "Yes" << endl; return 0;}
    }
  }
  cout << "No" << endl;
  return 0;
}
