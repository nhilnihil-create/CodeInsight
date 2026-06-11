#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N;
  
  for (int i = 0; i < N; i++){
    int l, r;
    cin >> l >> r;
    A = r - l + 1;
    B += A;
  }
  cout << B << endl;
}