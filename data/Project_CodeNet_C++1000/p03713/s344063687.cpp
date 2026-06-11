#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll three_diff(ll a, ll b, ll c)
{
    ll mx,mn;
    mx = max(a,b);
    mx = max(mx,c);
    mn = min(a,b);
    mn = min(mn,c);
    return mx-mn;
}

ll answer(ll h,ll w)
{
    ll nh;
    ll mn = LINF;
    for (nh = 0; nh <= h; nh++)
    {
        ll s1 = nh*w;
        ll s2 = (h-nh)*(w/2);
        ll s3 = (h-nh)*(w-w/2);
        ll temp1 = three_diff(s1, s2, s3);

        ll h_dash = h-nh;
        s2 = w * (h_dash / 2);
        s3 = w * (h_dash-h_dash/ 2);
        ll temp2 = three_diff(s1, s2, s3);
        mn = min(mn, temp1);
        mn=  min(mn, temp2);
    }
    return mn;

}

int main()
{
    ll h,w;
    cin >> h >> w;

    ll ans;
    ans = min(answer(h,w), answer(w,h));
    cout << ans << endl;
}