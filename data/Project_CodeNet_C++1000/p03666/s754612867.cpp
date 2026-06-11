// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 310;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, a, b, c, d;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> a >> b >> c >> d;

    if(c > d) swap(c,d);
    if(a > b) swap(a,b);
    b -= a; a = 0;

    bool ans = 0;
    for(int m = 0; m < n; m++)
    {
        int l = c*m-d*(n-m-1), r = d*m-c*(n-m-1);
        if(b >= l && b <= r) ans = 1;
    }
    if(ans) cout<<"YES";
    else cout<<"NO";
}



