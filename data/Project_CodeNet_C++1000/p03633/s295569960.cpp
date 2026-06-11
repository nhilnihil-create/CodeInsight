#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
int main() {

    ll N;
    cin >> N;
    ll ans = 1, T;

    rep(i, N) {
        cin >> T;
        ans = lcm(ans, T);
    }

    cout << ans;

    return 0;
}

ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}