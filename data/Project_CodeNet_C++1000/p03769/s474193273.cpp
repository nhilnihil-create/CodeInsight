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

const ll MAXN=1e6+10;

ll a[MAXN];

ll sz=1 , t=1;

ll solve(ll n)
{
    if (n==1)
    {
        return 0;
    }

    if (n%2==0)
    {
        ll x=solve(n/2);

        for(ll i=sz+1;i>=x+3;i--)
        {
            a[i]=a[i-2];
        }

        for(ll i=x+1;i>=2;i--)
        {
            a[i]=a[i-1];
        }

        a[1]=t;
        a[x+2]=t;

        t++;
        sz+=2;

        return x+1;
    }
    else
    {
        ll x=solve(n/2);

        for(ll i=sz+3;i>=x+5;i--)
        {
            a[i]=a[i-4];
        }

        for(ll i=x+1;i>=2;i--)
        {
            a[i]=a[i-1];
        }

        a[1]=t;
        a[x+4]=t;
        a[x+2]=t+1;
        a[x+3]=t+1;

        t+=2;
        sz+=4;

        return x+2;
    }
}

int main()
{
    ll n;
	cin>>n;

	solve(n);

	a[sz++]=t;
	a[sz++]=t;

    cout<<sz-1<<endl;

    for(ll i=1;i<sz;i++)
    {
        cout<<a[i]<<" ";
    }
}
