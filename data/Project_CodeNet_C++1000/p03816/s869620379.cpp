#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N;
  map<int, int> MA;
  while (cin >> A) MA[A]++;
  int cnt = 0;
  for (auto &ma : MA) {
    ma.second %= 2;
    if (!ma.second) ma.second += 2;
    if (ma.second == 2) cnt++;
  }
  cout << ((cnt % 2) ? MA.size() - 1 : MA.size()) << "\n";
}