#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll x = a / gcd(a, b);
    return x * b;
}

int main() {
    int N;
    cin >> N;
    vl T(N);
    rep(i, N) {
        cin >> T[i];
    }

    if (N == 1) {
        cout << T[0] << endl;
        return 0;
    }

    ll ans = lcm(T[0], T[1]);
    for (int i = 2; i < N; i++) {
        ans = lcm(ans, T[i]);
    }

    cout << ans << endl;
}