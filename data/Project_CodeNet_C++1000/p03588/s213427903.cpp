#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;


int main() {
  ll N; cin >> N;
  ll result = LLINF;
  rep(i,N) {
    ll A, B; cin >> A >> B;
    result = min(result, A+B);
  }
  cout << result << endl;
  return 0;
}