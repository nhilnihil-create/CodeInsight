#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int A = 0;
  
  for(int i = 0; i < X; i++) {
    int l, r;
    cin >> l >> r;
    A += 1;
    A += r;
    A -= l;
  }
  cout << A << endl;
}