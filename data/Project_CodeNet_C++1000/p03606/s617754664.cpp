#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  int l = 0;
  int r = 0;

  int sum = 0;

  for (int i = 0 ; i < N ; i++) {
    cin >> l >> r;
    sum += r - l + 1;
  }

  cout << sum << endl;

}

