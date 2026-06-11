#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
using namespace std;

ll a,b,c,d,e,f,g,ans;

int main()
{
    cin >> a >> b >> c >> d >> e >> f >> g;
    ll ans1 = 0;
    if (d && a && e) ans1 = (d-1) / 2 * 2 + (e-1) / 2 * 2 + (a-1) / 2 * 2 + 3;
    ll ans2 = d / 2 * 2 + e / 2 * 2 + a / 2 * 2;
    cout << b + max(ans1,ans2) << '\n';
    return 0;
}
