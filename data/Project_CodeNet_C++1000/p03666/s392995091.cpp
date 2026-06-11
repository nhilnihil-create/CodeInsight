#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  ll diff = B-A;
  string result = "NO";
  rep(i,N-1) {
    ll l = C*i - D*((N-1)-i);
    ll r = D*i - C*((N-1)-i);
    if (l<=diff && r>=diff) result = "YES";
  }
  cout << result << endl;
  return 0;
}