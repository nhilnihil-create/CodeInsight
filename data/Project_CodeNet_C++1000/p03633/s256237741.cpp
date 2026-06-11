#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    ll n; cin >> n;
    V<ll> t(n);
    for(ll i = 0; i < n; i++) cin >> t[i];

    ll l = t[0];
    for(ll i = 1; i < n; i++){
        l = lcm(l, t[i]);
    }
    cout << l << endl;

}
