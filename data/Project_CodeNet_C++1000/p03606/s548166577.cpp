#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int t;
  int u=0;
  for (int i = 0; i < N; i++){
    int l,r;
    cin >> l >> r;
    t=r-l+1;
    u+=t;
  }
  cout << u << endl;
}
