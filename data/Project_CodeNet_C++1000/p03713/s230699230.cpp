/**
 * Title:
 * Url:
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>

using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    ll h, w; cin >> h >> w;
    ll ans = INF;
    for(ll i=1; i<h+1; i++) {
        ll a = h-i;
        // 垂直方向に分割
        ll b = w/2;
        ll sa = w*i;
        ll sb = a*b;
        ll sc = a*(w-b);
        ll max_s = max(sa, max(sb, sc));
        ll min_s = min(sa, min(sb, sc));
        ans = min(ans, (max_s-min_s));
        // 水平方向に分割
        b = a/2;
        sb = w*b;
        sc = w*(a-b);
        max_s = max(sa, max(sb, sc));
        min_s = min(sa, min(sb, sc));
        ans = min(ans, (max_s-min_s));
    }
    for(ll i=1; i<w+1; i++) {
        ll a = w-i;
        // 垂直方向に分割
        ll b = h/2;
        ll sa = h*i;
        ll sb = a*b;
        ll sc = a*(h-b);
        ll max_s = max(sa, max(sb, sc));
        ll min_s = min(sa, min(sb, sc));
        ans = min(ans, (max_s-min_s));
        // 水平方向に分割
        b = a/2;
        sb = h*b;
        sc = h*(a-b);
        max_s = max(sa, max(sb, sc));
        min_s = min(sa, min(sb, sc));
        ans = min(ans, (max_s-min_s));
    }
    cout << ans << endl;
    return 0;
}