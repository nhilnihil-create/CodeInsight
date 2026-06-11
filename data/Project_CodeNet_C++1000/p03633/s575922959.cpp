#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

//最大公約数
ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    int N;
    cin >> N;
    vector<ll> T(N);
    for(int i=0; i<N; i++) cin >> T[i];

    ll ans = 1;
    for(int i=0; i<N; i++) {
        ans = lcm(ans, T[i]);
    }
    cout << ans << endl;
}