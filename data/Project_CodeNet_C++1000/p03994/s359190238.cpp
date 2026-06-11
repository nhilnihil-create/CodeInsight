#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  ll N[S.size()];
  for (int i = 0; i < S.size(); i++) {
    N[i] = (123 - S[i]) % 26;
  }
  for (int i = 0; i < S.size(); i++) {
    if (N[i] <= K) {
      S[i] = 'a';
      K -= N[i];
    }
  }
  K = K % 26;
  S[S.size() - 1] += K;
  cout << S << endl;
  return 0;
}
