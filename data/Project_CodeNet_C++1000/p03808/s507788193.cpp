#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    a[n+1]=a[1];

    ll t=sum/(n*(n+1)/2);
    if(sum%(n*(n+1)/2))
    {
        cout<<"NO";
        return 0;
    }
    ll p=0;
    for(int i=1;i<=n;i++)
    {

        if(a[i+1]-a[i]>t)
        {
            cout<<"NO"<<'\n';
            return 0;
        }
        if((a[i+1]-a[i]-t)%n)
        {
            cout<<"NO"<<'\n';
            return 0;
        }
        p+=(t-(a[i+1]-a[i]))/n;
        //cout<<p<<'\n';
    }
    if(p!=t)
        {
            cout<<"NO"<<'\n';
            return 0;
        }
    cout<<"YES"<<'\n';
}
