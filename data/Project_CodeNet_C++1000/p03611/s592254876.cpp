#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> memo(100002);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    memo.at(a.at(i) + 1)++;
    memo.at(a.at(i))++;
    memo.at(a.at(i) + 2)++;
  }
  int ans = 0;
  for (int i = 0; i < 100000; i++) {
    ans = max(ans, memo.at(i));
  }
  cout << ans << endl;
}