#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int total = 0;
  for (int i = 0; i < N; i++) {
    int r, l;
    cin >> r >> l;
    int part = l - r + 1;
    total += part;
  }
  cout << total << endl;
}