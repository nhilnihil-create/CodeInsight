#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    ll N; cin >> N;
    vector<ll> T(N), A(N);
    rep(i, N) cin >> T[i] >> A[i];
    ll a=1, b=1;
    rep(i, N) {
        ll x = max((a+T[i]-1)/T[i], (b+A[i]-1)/A[i]);
        a = T[i]*x; b = A[i]*x;
    }
    cout << a + b;
}
