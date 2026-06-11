#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

ll solve(ll h, ll w) {
    ll mn = w*h, a[3] = {};
    for (ll i = 1; i < w; ++i) {
        a[0] = i * h;
        a[1] = (w-i)/2 * h;
        a[2] = w*h - a[0] - a[1];
        sort(a, a+3);
        mn = min(mn, a[2]-a[0]);

        a[0] = i * h;
        a[1] = h/2 * (w-i);
        a[2] = h*w - a[0] - a[1];
        sort(a, a+3);
        mn = min(mn, a[2]-a[0]);
    }
    return mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    ll h, w;
    cin >> h >> w;
    ll a = solve(h, w);
    ll b = solve(w, h);
    cout << min(a, b) << endl;
}
