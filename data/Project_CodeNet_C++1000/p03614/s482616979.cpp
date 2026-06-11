#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,p[100005],rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>p[i];

    for(ll i=1;i<=n;i++)
    {
        if(p[i]==i)
        {
            if(i==n)
                rez++;
            else
            {
                ll x=p[i];
                p[i]=p[i+1];
                p[i+1]=x;
                rez++;
            }
        }
    }

    cout<<rez<<endl;

    return 0;
}
