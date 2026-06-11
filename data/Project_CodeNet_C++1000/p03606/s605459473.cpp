#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, answer, l, r;
  for (cin >> N, answer = 0; N; N--) {
    cin >> l >> r;
    answer += r-l+1;
  }
  cout << answer;
}