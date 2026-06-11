#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    int xl = 0;
    int yd = 0;
    int xr = w;
    int yu = h;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1) xl = max(xl, x);
        if(a == 2) xr = min(xr, x);
        if(a == 3) yd = max(yd, y);
        if(a == 4) yu = min(yu, y);
    }
    int wi = max(0, xr - xl);
    int he = max(0, yu - yd);
    cout << wi * he << endl;
    return 0;
}