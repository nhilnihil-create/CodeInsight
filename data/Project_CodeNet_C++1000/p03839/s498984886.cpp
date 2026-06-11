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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = max(0LL, a[i]);
    }

    vector<ll> ruiA(n+1), ruiB(n+1);  // ruiA[i+1] : a[i]までの累積和
    rep(i, n) {
        ruiA[i+1] = ruiA[i] + a[i];
        ruiB[i+1] = ruiB[i] + b[i];
    }

    ll ans = 0;
    rep(i, n-k+1) {  // a[i]から始まる長さkの区間(a[i] ～ a[i+(k-1)])を塗る
        rep(color, 2) {  // 上記の長さkの区間を、0のとき白、1のとき黒に塗る

            ll now = (ruiB[i] - ruiB[0]) + (ruiB[n] - ruiB[i+k]);
            
            if(color) {
                now += ruiA[i+k] - ruiA[i];
            }
            
            ans = max(ans, now);
        }
    }
    
    cout << ans << endl;
    return 0;
}