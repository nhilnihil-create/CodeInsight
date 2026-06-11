#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N; ll x;
    cin >> N >> x;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    if (a[0] > x) {
        ans += a[0] - x;
        a[0] = x;
    }
    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i+1] <= x) continue;
        ll diff = max(0LL, x - a[i]);
        ans += a[i+1] - diff;
        a[i+1] = diff;
    }
    cout << ans << '\n';
}
