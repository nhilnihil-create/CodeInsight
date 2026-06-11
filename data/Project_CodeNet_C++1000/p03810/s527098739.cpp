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
const ll MAX_LOG=40;

ll a[MAXN];

ll n;

ll solve()
{
    ll e=0 , z=0;

    for(ll i=1;i<=n;i++)
    {
        e+=(a[i]%2==0);
        z+=(a[i]&1 && a[i]>1);
    }

    if (e&1)
    {
        return 1;
    }

    if (e==n-1 && z==1)
    {
        ll g=0;

        for(ll i=1;i<=n;i++)
        {
            if (a[i]&1)
            {
                a[i]--;
            }

            if (g==0)
            {
                g=a[i];
            }
            else
            {
                g=__gcd(g , a[i]);
            }
        }

        for(ll i=1;i<=n;i++)
        {
            a[i]/=g;
        }

        return 1-solve();
    }

    return 0;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

	if (n==1)
    {
        if (n&1)
        {
            cout<<"Second";
        }
        else
        {
            cout<<"First";
        }

        return 0;
    }

	if (solve())
    {
        cout<<"First";
    }
    else
    {
        cout<<"Second";
    }
}
