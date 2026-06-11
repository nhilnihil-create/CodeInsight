#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    ll Q, H, S, D;
    cin >> Q >> H >> S >> D;
    ll n;
    cin >> n;

    ll ans = 1e18;
    ll half = H;
    chmin(half, Q*2LL);
    ll one = S;
    chmin(one, half*2LL);
    ll two = D;
    chmin(two, one*2LL);

    chmin(ans, one*n);
    chmin(ans, two*(n/2LL)+one*(n%2));

    cout << ans << endl;
}