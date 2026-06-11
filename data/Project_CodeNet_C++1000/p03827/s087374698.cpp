#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  int now = 0;
  for (auto c : S) {
    if (c == 'I') now++;
    else now--;
    ans = max(ans, now);
  }
  cout << ans << "\n";
}