#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int sumx = 0;
  int sumy = 0;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    sumx += l;
    sumy += r;
  }
  
  cout << sumy - sumx + N << endl;

}
