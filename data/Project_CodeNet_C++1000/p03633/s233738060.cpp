#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<ll> T;


void input() {
    cin >> N;
    T = vector<ll>(N);
    rep(i, N) cin >> T[i];
}


// 最大公約数
ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}


// 最小公倍数
ll lcm(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a / gcd(a, b)) * b;
}


int main() {
    input();
    ll ans = 1;
    rep(i, N) ans = lcm(ans, T[i]);
    cout << ans << endl;
}
