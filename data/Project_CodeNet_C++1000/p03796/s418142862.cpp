#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, O = 1;
  cin >> N;
  for (ll i = 2; i <= N; i++) {
    O *= i;
    O %= 1000000007;
  }
  cout << O << endl;
}