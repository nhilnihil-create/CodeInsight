#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> total(n,0);
    total[0]=a[0];
    rep(i,n-1)
    {
        total[i+1]=total[i]+a[i+1];
    }
    int ans=n;
    int point=0;
    ll now=a[0];
    rep(i,n-1)
    {
        if(a[i+1]>now*2)
        {
            //cout<<i+1<<endl;
            ans-=i-point+1;
            point=i+1;
        }
        now=total[i+1];
        
        
    }
    cout<<ans;
}
