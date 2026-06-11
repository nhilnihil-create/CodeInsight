#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,x[100005],y[100005],r1,r2,rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>x[i];
    for(ll i=1;i<=m;i++)
        cin>>y[i];
    sort(x+1,x+1+n);
    sort(y+1,y+1+m);

    for(ll i=1;i<=n;i++)
    {
        r1+=x[i]*(i-1-(n-i));
        r1%=1000000007;
    }
    for(ll i=1;i<=m;i++)
    {
        r2+=y[i]*(i-1-(m-i));
        r2%=1000000007;
    }
    rez=r1*r2;
    rez%=1000000007;

    cout<<rez<<endl;

    return 0;
}
