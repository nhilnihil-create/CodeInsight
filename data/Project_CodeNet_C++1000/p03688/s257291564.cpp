// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 1e6+10;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, a[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    int mn = n, mx = 0;
    for(int i = 1; i <= n; i++) 
    {cin>> a[i]; mn = min(mn,a[i]); mx = max(mx,a[i]);}

    if(mx - mn > 1) return cout<<"No", 0;
    if(mn == mx)
    {
        if(mx == n-1) return cout<<"Yes", 0;
        if(mx <= n/2) cout<<"Yes";
        else cout<<"No";
        return 0;
    }

    int d = mx, x = 0, y = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] == mn) x++;
        else y++;
    
    if(d <= x+y/2 && d >= x+1) cout<<"Yes";
    else cout<<"No";
}



