#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool prev = false;
  int answer = 0;
  int p;
  for (int ni = 0; ni < n; ni++) {
    cin >> p;
    if (p == ni + 1) {
      if (prev) {
        prev = false;
      } else {
        answer++;
        prev = true;
      }
    } else {
      prev = false;
    }
  }
  cout << answer << endl;
  return 0;
}