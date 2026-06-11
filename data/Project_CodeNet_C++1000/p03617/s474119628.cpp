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
    vector<ll> v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];
    ll N;
    cin >> N;

    ll a = min({v[0] * 4, v[1] * 2, v[2]});
    ll b = min(2 * a, v[3]);

    ll ans = (N / 2) * b + ((N % 2) ? a : 0);
    cout << ans << '\n';
}
