#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

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

int main() {
    int N;
    ll t;
    cin >> N;
    ll X = 1;
    for(int i=0; i<N; i++) {
        cin >> t;
        X = lcm(X, t);
    }
    cout << X << endl;
}