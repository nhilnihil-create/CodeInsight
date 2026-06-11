#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  deque<int> D;
  for (int i = 0; i < N; i++) {
    if (i % 2) D.push_front(A.at(i));
    else D.push_back(A.at(i));
  }
  if (N % 2) reverse(D.begin(), D.end());
  for (auto d : D) cout << d << "\n";
}