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
#define SQ 500
#define INF 1e9+7

using namespace std;

ll n,m,a,b;
ll ans[N];
pi ar[N];
ll seg[4*N];
ll lazy[4*N];

void relax(ll low,ll high,ll pos)
{
    if(lazy[pos])
    {
        seg[pos] += lazy[pos];

        if(low!=high)
        {
            lazy[pos*2+1]+=lazy[pos];
            lazy[pos*2+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }

    return;
}

void update(ll low,ll high,ll pos,ll slow,ll shigh,ll val)
{
    relax(low,high,pos);

    if(low>=slow&&high<=shigh)
    {
        lazy[pos] += val;
        relax(low,high,pos);
        return;
    }
    if(low > shigh||high<slow)
        return;

    ll mid = (low+high)/2;
    update(low,mid,pos*2+1,slow,shigh,val);
    update(mid+1,high,pos*2+2,slow,shigh,val);
    return;
}

ll query(ll low,ll high,ll pos,ll slow)
{
    relax(low,high,pos);

    if(low == slow && high == low)
        return seg[pos];
    if(low>slow||high<slow)
        return 0;
    ll mid = (low+high)/2;

    return query(low,mid,pos*2+1,slow)+query(mid+1,high,pos*2+2,slow);
}

bool cmp(const pi &a,const pi &b)
{
    if(a.second-a.first == b.second-b.first)
        return a < b;

    return a.second-a.first>b.second-b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    rep(i,0,n)
    {
        cin >> ar[i].first >> ar[i].second;
        update(0,m,0,ar[i].first,ar[i].second,1);
    }

    sort(ar,ar+n,cmp);

    ll cur = 0;

    for(int length=m;length>=1;length--)
    {
        while(cur < n && ar[cur].second-ar[cur].first+1>=length)
        {
            update(0,m,0,ar[cur].first,ar[cur].second,-1);
            cur++;
        }

        ans[length] = cur;

        for(int i = 0;i <= m;i += length)
        {
            ans[length] += query(0,m,0,i);
        }
    }

    rep(i,1,m+1)
        cout << ans[i] << "\n";

    return 0;
}
