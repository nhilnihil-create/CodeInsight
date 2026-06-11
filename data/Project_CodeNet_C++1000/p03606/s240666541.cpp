#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  
  int total = 0;
  for( int i = 0; i < N; ++i ){
    int l = 0, r = 0;
    cin >> l >> r;
    r -= l;
    total += r + 1;
  }
  cout << total;
}