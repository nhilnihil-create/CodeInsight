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
const int mod = 998244353;
const int inf = 1e18+10;

int n, k;
int a[maxn], ps[maxn], sf[maxn];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> k;
    int sm = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>> a[i];
        ps[i] = ps[i-1] + max(a[i],0ll);
        if(i < k) sm += a[i];
    }
    for(int i = n; i >= 1; i--) sf[i] = sf[i+1] + max(a[i],0ll);

    ll ans = 0;
    for(int i = k; i <= n; i++)
    {
        sm -= a[i-k]; sm += a[i];
        ans = max(ans, ps[i-k] + sf[i+1] + max(sm,0ll));
    }
    cout<< ans;
}


