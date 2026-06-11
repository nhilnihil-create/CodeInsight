#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

const ll MAXN=1e5+10;

struct segment
{
    ll l , r , sign;
};

segment z[MAXN];
segment ps[MAXN];
segment res[MAXN];

ll a[MAXN];
ll x[MAXN];
ll ans[MAXN];

ll n;

segment merge_segment(segment b , segment c)
{
    segment res;

    if (b.sign==c.sign)
    {
        res.sign=b.sign;
        res.l=min(b.l , c.l);
        res.r=max(b.r , c.r);
    }
    else
    {
        if ((b.r-b.l+1)<(c.r-c.l+1))
        {
            swap(b , c);
        }

        res.sign=b.sign;

        if (b.l==c.l)
        {
            res.l=c.r+1;
        }
        else
        {
            res.l=b.l;
        }

        if (b.r==c.r)
        {
            res.r=c.l-1;
        }
        else
        {
            res.r=b.r;
        }
    }

    return res;
}

void perform(segment b[MAXN] , segment c[MAXN])
{
    ps[0].l=0;
    ps[0].r=0;
    ps[0].sign=1;

    for(ll i=1;i<=n;i++)
    {
        ps[i]=merge_segment(ps[i-1] , c[i]);
    }

    for(ll i=1;i<=n;i++)
    {
        ll l=b[i].l , r=b[i].r , sign=b[i].sign;
        ps[l-1].sign=-ps[l-1].sign;
        b[i]=merge_segment(ps[r] , ps[l-1]);
        ps[l-1].sign=-ps[l-1].sign;

        if (sign==-1)
        {
            b[i].sign=-b[i].sign;
        }
    }
}

void pw(ll k)
{
    if (k==0)
    {
        return;
    }

    pw(k/2);
    perform(res , res);

    if (k&1)
    {
        perform(res , z);
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>x[i];
    }

    ll m , k;
    cin>>m>>k;

    for(ll i=1;i<=m;i++)
    {
        cin>>a[i];
    }

    for(ll i=1;i<=n;i++)
    {
        z[i].l=i;
        z[i].r=i;
        z[i].sign=1;
    }

    for(ll i=m;i>=1;i--)
    {
        z[a[i]-1]=merge_segment(z[a[i]-1] , z[a[i]]);
        z[a[i]+1]=merge_segment(z[a[i]+1] , z[a[i]]);
        z[a[i]].sign=-z[a[i]].sign;
    }

    for(ll i=1;i<=n;i++)
    {
        res[i].l=i;
        res[i].r=i;
        res[i].sign=1;
    }

    pw(k);

    for(ll i=1;i<=n;i++)
    {
        ans[res[i].l]+=res[i].sign*x[i];
        ans[res[i].r+1]-=res[i].sign*x[i];
    }

    for(ll i=1;i<=n;i++)
    {
        ans[i]+=ans[i-1];
        cout<<ans[i]<<endl;
    }
}

/*
5
1 1 1 1 1
3 1
2 3 4
*/
