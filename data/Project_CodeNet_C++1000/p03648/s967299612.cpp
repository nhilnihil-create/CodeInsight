#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k,a[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>k;

    for(ll i=0;i<50;i++)
        a[i]=i;

    ll d=k/50;
    if(k%50==0)
    {
        for(ll i=0;i<50;i++)
            a[i]+=d;
    }
    else
    {
        for(ll i=0;i<50;i++)
            a[i]+=d;
        k%=50;
        ll p=0;
        while(k)
        {
            k--;
            a[p]+=50;
            for(ll i=0;i<50;i++)
                if(i!=p)
                    a[i]--;
            p++;
        }
    }

    cout<<50<<endl;
    for(ll i=0;i<50;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
