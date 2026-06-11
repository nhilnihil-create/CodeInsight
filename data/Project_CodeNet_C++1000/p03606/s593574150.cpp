#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
  cin >> N;
  int l, r, sum = 0;
  for (int i = 0; i < N; i++){
    cin >> l >> r;
    sum += r - l + 1;
  }
  cout << sum << endl;
}