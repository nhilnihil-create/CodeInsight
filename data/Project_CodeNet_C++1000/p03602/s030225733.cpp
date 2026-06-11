#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[305][305],rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>a[i][j];

    for(ll i=2;i<n;i++)
        for(ll j1=1;j1<i;j1++)
            for(ll j2=i+1;j2<=n;j2++)
                if(a[j1][i]+a[i][j2]<a[j1][j2])
    {
        cout<<-1<<endl;
        return 0;
    }

    for(ll i=1;i<=n-1;i++)
        for(ll j=i+1;j<=n;j++)
    {
        ll ind=0;
        for(ll k=1;k<=n;k++)
        {
            if(k!=i&&k!=j)
                if(a[i][k]+a[k][j]==a[i][j])
                    ind=1;
        }

        if(ind==0)
            rez+=a[i][j];
    }

    cout<<rez<<endl;

    return 0;
}
