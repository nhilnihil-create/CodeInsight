#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int64_t color = (int64_t)k;
  if(n != 1) {
    for(int i = 1; i < n; i++) color *= (k - 1);
  }
  cout << color;
}