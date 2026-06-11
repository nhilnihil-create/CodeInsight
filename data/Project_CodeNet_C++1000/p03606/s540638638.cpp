#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum;
  cin >> N;
  sum = N;
  for(; N > 0; N--) {
    int l, r;
    cin >> l >> r;
    sum += r - l;
  }
  cout << sum << endl;
}