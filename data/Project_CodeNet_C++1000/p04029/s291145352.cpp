#include<bits/stdc++.h>

using namespace std;

int calc_sum (int x) {
  if (x == 1) return 1;
  else return x + calc_sum(x - 1);
}

int main() {
  int n, result;
  cin >> n;
  result = calc_sum(n);
  cout << result << endl;
  return 0;
}