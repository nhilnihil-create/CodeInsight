#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

ll kaizyou(ll k) { 
    ll sum = 1;
    for (ll i = 1; i <= k; i++){
      sum *= i%MOD;
      sum %= MOD;
    }
    return sum%MOD;
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll out = (kaizyou(N) % MOD) * (kaizyou(M) % MOD);
    if (N == M) {
      out *= 2;
      out %= MOD;
    } else if (abs(N - M) > 1) {
      out = 0;
    }
    cout << out%MOD << endl;
    return 0;
}