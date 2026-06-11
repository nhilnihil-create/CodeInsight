#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int l;
  int t;
  int kyaku = 0;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> l >> t;
    kyaku += t - l + 1;
  }
  cout << kyaku << endl;
}