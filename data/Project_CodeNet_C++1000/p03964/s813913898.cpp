#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e9+7;
ll a[2000];
ll b[2000];
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];

    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1]||b[i]<b[i-1])
        {
            ll t=max(ceil((long double)a[i-1]/a[i]),ceil((long double)b[i-1]/b[i]));
            a[i]*=t;
            b[i]*=t;
        }
    }
    cout<<a[n-1]+b[n-1]<<endl;
    return 0;
}
