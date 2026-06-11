#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int total = 0;
  
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l -1; j < r; j++) total++;
  }
  cout << total << endl;
}