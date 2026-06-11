#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    ll res = b + 2*(a/2) + 2*(d/2) + 2*(e/2);
    if(a && d && e) res = max(res, b + 3 + 2*((a-1)/2) + 2*((d-1)/2) + 2*((e-1)/2));
    cout << res;
    return 0;
}
