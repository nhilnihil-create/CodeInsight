#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, N, answer = 0;
  map<int,int> B;
  for (cin >> N; N; B[A]++, B[A] %= 2, N--) {
    cin >> A;
  }
  for (auto p : B) {
    answer += p.second;
  }
  cout << answer;
}