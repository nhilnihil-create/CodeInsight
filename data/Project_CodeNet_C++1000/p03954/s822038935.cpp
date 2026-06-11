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

const ll MAXN=2e5+10;

ll a[MAXN];

ll n;

bool check(ll x)
{
    ll l=n , r=n;

    while (r<2*n-1)
    {
        if ((a[l-1]<=x)==(a[l]<=x) || (a[r+1]<=x)==(a[r]<=x))
        {
            return (a[l]<=x);
        }

        l--;
        r++;
    }

    return (n&1 ? (a[n]<=x) : (a[n]>x));
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(ll i=1;i<=2*n-1;i++)
    {
        cin>>a[i];
    }

    ll L=0 , R=2*n-1;

    while (R-L>1)
    {
        ll mid=(L+R)/2;

        if (check(mid))
        {
            R=mid;
        }
        else
        {
            L=mid;
        }
    }

    cout<<R;
}
