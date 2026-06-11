#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P, L, R, T,tot;
  P = 1;
  cin >> N;
  tot=0;
  while( N-P>=0){
    cin >> L >> R;
    T=R-L+1;
    tot=tot+T;
    P++;
  }
 cout << tot << endl;
}
