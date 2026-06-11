#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, l, r, cnt=0;
  cin >> N;
 
  for (int i = 0; i < N; i++) {
    cin >> l >> r;
    for (int j = l; j <= r; j++) {
      cnt++;
    }
  }
 
  cout << cnt << endl;
}