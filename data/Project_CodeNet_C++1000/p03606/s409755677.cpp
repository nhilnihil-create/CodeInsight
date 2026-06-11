#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,j,t,y = 0; 
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> j >> t;
    y += t - j + 1;
  }
  cout << y << endl;
}