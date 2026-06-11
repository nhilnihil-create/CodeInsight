#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> T(N), A(N);
  for (int i = 0; i < N; i++) cin >> T.at(i) >> A.at(i);
  long long t = 1, a = 1;
  for (int i = 0; i < N; i++) {
    long long n = max((t + T.at(i) - 1) / T.at(i), (a + A.at(i) - 1) / A.at(i));
    t = n * T.at(i);
    a = n * A.at(i);
  }
  cout << t + a << endl;
}