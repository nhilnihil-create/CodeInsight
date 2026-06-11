#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> ans(101);
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  for (int i = A; i < B; i++) {
    ans.at(i)++;
  }
  for (int i = C; i < D; i++) {
    ans.at(i)++;
  }
  int cnt = 0;
  for (int i = 0; i < 101; i++) {
    if (ans.at(i) == 2) cnt++;
  }
  cout << cnt << "\n";
}