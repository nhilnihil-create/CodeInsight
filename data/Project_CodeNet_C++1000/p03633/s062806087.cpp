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
ll gcd(ll x, ll y) { return (y ? gcd(y, x % y) : x); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];
    ll ans = p[0];
    for (int i = 1; i < N; i++) ans = lcm(ans, p[i]);
    cout << ans << '\n';
}
