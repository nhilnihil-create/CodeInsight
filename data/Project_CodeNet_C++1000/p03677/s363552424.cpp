#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e16

using namespace std;

ll n,m,ar[N];
ll seg[4*N][2];
ll lazy[4*N][2];

void relax(ll low,ll high,ll pos,ll id)
{
    if(lazy[pos][id] != 0)
    {
        seg[pos][id] += lazy[pos][id];

        if(low != high)
        {
            lazy[pos*2+1][id] += lazy[pos][id];
            lazy[pos*2+2][id] += lazy[pos][id];
        }

        lazy[pos][id]=0;
    }

    return;
}

void update(ll low,ll high,ll pos,ll slow,ll shigh,ll val,ll id)
{
    relax(low,high,pos,id);
    if(slow > shigh)
        return;

    if(low >= slow && high <= shigh)
    {
        seg[pos][id] += val;

        if(low != high)
        {
            lazy[pos*2+1][id] += val;
            lazy[pos*2+2][id] += val;
        }

        return;
    }
    if(low > shigh || high < slow)
        return;

    ll mid = (low+high)/2;

    update(low,mid,pos*2+1,slow,shigh,val,id);
    update(mid+1,high,pos*2+2,slow,shigh,val,id);

    return;
}

ll getval(ll low,ll high,ll pos,ll slow)
{
    relax(low,high,pos,0);
    relax(low,high,pos,1);

    if(low == high && low == slow)
    {
        return seg[pos][0] + seg[pos][1]*slow;
    }
    if(low > slow || high < slow)
        return 0;

    ll mid = (low+high)/2;

    return getval(low,mid,pos*2+1,slow)+getval(mid+1,high,pos*2+2,slow);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    rep(i,0,n)
        cin >> ar[i];

    rep(i,0,n-1)
    {
        ll arxi = ar[i];
        ll telos = ar[i+1];

        if(ar[i] == ar[i+1])
            continue;
        else if(ar[i] < ar[i+1])
        {
            update(0,m,0,1,ar[i],ar[i+1]-ar[i],0);
            update(0,m,0,ar[i+1]+1,m,ar[i+1]-ar[i],0);

            update(0,m,0,ar[i]+1,ar[i+1],-1,1);
            update(0,m,0,ar[i]+1,ar[i+1],ar[i+1]+1,0);
        }
        else
        {
            update(0,m,0,1,ar[i+1],-1,1);
            update(0,m,0,1,ar[i+1],ar[i+1]+1,0);

            update(0,m,0,ar[i]+1,m,-1,1);
            update(0,m,0,ar[i]+1,m,m+ar[i+1]+1,0);

            update(0,m,0,ar[i+1]+1,ar[i],m-ar[i]+ar[i+1],0);
        }
    }

    ll ans = INF;

    rep(i,1,m+1)
    {
        ll res = getval(0,m,0,i);

//        cout << i << "  " << res << endl;
        ans = min(ans,res);
    }

    cout << ans;

    return 0;
}

