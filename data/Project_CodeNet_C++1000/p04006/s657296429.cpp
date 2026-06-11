#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
 
int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    vector<vector<ll>> b(n, vector<ll>(n));  // b[k][i] : 魔法をk回使うとき色iのスライムを手に入れるのにかかる時間の最小値
    ll ans = 0;
    rep(i, n) {
        cin >> a[i];
        ans += a[i];
        b[0][i] = a[i];
    }

    for(int k = 1; k < n; k++) {

        rep(i, n) {

            if(i >= k) {
                b[k][i] = min(b[k-1][i], a[i-k]);
            }
            else {
                b[k][i] = min(b[k-1][i], a[n+i-k]);
            }

        }

        ll now = k*x;
        rep(i, n) {
            now += b[k][i];
        }

        ans = min(ans, now);
    }
    
    cout << ans << endl;
    return 0;
}