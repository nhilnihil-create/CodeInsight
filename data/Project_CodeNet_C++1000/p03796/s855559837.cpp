#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int N; cin >> N;
  ll ans =1;
  for (int i =1; i<=N; i++) {
    ans *= i; ans %= 1000000007;
  }
  cout << ans << endl;
}