#include <bits/stdc++.h>
using namespace std;

int main() {
  int N=0;
  cin >> N;

  // ここにプログラムを追記
  int L=0,R=0,i=0,Sum=0;
  for (int i=0; i<N; i++) {
    cin >> L >> R;
    Sum+=R-L+1;
  }
  cout << Sum <<endl;
}
