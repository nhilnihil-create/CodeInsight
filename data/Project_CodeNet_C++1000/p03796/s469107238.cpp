#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, answer = 1;
  cin >> N;
  for (int i = 2; i <= N; i++) {
    answer *= i;
    answer %= 1000000007;
  }
  cout << answer;
}