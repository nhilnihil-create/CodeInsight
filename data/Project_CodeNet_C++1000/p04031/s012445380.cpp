#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  int result = 4000000;
  for (int i = -100; i <= 100; i++) {
    int adder = 0;
    for (int j = 0; j < N; j++) {
      int tmp = (a.at(j) - i) * (a.at(j) - i);
      adder += tmp;
    }
    result = min(adder, result);
  }
  cout << result << endl;
}