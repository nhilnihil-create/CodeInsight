#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, z;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    z += y - x + 1;
  }
  
  cout << z;
}