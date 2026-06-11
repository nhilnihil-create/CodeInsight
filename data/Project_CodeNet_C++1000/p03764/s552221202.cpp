#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> x(N);
    vector<ll> y(M);
    for(int i = 0;i < N;i++) {
        cin >> x.at(i);
    }
    for(int i = 0;i < M;i++) {
        cin >> y.at(i);
    }
    ll ret1 = 0;
    ll ret2 = 0;
    for(int i = 0;i < N - 1;i++) {
        ret1 += (x.at(i + 1) - x.at(i)) % MOD * (i + 1) % MOD * (N - 1 - i) % MOD;
        ret1 %= MOD;
    }
    for(int i = 0;i < M - 1;i++) {
        ret2 += (y.at(i + 1) - y.at(i)) % MOD * (i + 1) % MOD * (M - 1 - i) % MOD;
        ret2 %= MOD;
    }
    cout << ret1 * ret2 % MOD << endl;
}