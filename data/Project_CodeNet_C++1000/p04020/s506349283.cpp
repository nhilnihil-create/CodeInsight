#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
main()
{
    int n;
    cin>>n;
    int last=0;
    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(last==1&&x>=1)
        {
            last=0;
            ans++;
            x--;
        }
        ans+=x/2;
        last=x%2;
    }
    cout<<ans;

}
