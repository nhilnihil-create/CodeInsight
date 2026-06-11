#include <iostream>

using namespace std;

int main() {
  int N, P{}, M{};
  string S;
  cin >> N >> S;
  for (int i = 0; i != N; ++i) {
    if (S[i] == '(') ++P;
    else --P;
    M = min(M, P);
  }
  cout << string(-M,'(') << S << string(P-M,')') << endl;
}
