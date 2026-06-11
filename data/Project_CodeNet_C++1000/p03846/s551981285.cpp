#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int M = 1e9+7;

using namespace std;

ll fexp (ll x, ll y)
{
    ll r=1;
    while (y)
    {
        if (y&1)
            r=(r*x)%M;
        x=(x*x)%M;
        y>>=1;
    }
    return r;
}

main()
{
    fast;
    int n,i;
    cin>>n;
    int a[n];
    for (i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int f=0;
    if (n&1)
    {
        if (a[0]!=0)
            f=1;
        else
        {
            for (i=1;i<n;i+=2)
            {
                if (a[i]==i+1 && a[i+1]==i+1)
                    continue;
                else
                {
                    f=1;
                    break;
                }
            }
        }
        if (!f)
            cout<<fexp(2,n/2)%M<<endl;
        else
            cout<<"0\n";
    }
    else
    {
        for (i=0;i<n;i+=2)
        {
            if (a[i]==i+1 && a[i+1]==i+1)
                continue;
            else
            {
                f=1;
                break;
            }
        }
        if (!f)
            cout<<fexp(2,n/2)%M<<endl;
        else
            cout<<"0\n";
    }
}