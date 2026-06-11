#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,t,a[100005],m,M,d,rez;
unordered_set<ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>t;
    t-=(t%2==1);
    for(ll i=0;i<n;i++)
        cin>>a[i];

    m=a[0];
    M=a[0];
    for(ll i=1;i<n;i++)
    {
        if(a[i]>M)
        {
            M=a[i];
            if(d<M-m)
                d=M-m;
        }
        if(a[i]<m)
        {
            m=a[i];
            M=a[i];
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(s.count(a[i]-d))
            rez++;
        s.insert(a[i]);
    }

    cout<<rez<<endl;

    return 0;
}
