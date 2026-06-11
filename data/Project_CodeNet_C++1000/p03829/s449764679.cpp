#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
   ll N, A, B;
   cin >> N >> A >> B;
   vector<ll> X(N);
   rep(i, 0, N) cin >> X.at(i);

   ll ans = 0;
   rep(i, 0, N - 1) {
     ans += min(B, A * (X.at(i + 1) - X.at(i)));
   }

   cout << ans << endl;
 }
