#include <bits/stdc++.h>
using namespace std;
int main() {
  int answer = 0, N, K, x;
  for (cin >> N >> K; N; N--) {
    cin >> x;
    answer += 2*min(x,abs(K-x));
  }
  cout << answer;
}