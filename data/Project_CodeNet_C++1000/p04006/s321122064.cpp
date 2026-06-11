// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
#define pii pair<int,int>
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 2010;
const int mod = 998244353;
const int inf = 1e18+10;

int n, x;
int a[maxn];
vector<int> stk;
int mn[maxn][maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> x;
    for(int i = 0; i < n; i++) cin>> a[i];

    int ans = inf;
    for(int t = 1; t <= n; t++)
    {
        int cost = x*(t-1);
        for(int l = 0; l < n; l++)
        {
            int r = (l+t-1) % n;
            if(l == r)
            {
                mn[l][r] = a[l];
                cost += mn[l][r];
                continue;
            }
            mn[l][r] = min(a[l], mn[(l+1)%n][r]);
            cost += mn[l][r];
        }
        ans = min(ans,cost);
    }
    cout<< ans;
}

 


 