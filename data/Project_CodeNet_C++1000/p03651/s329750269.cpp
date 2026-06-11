#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;

ll gcd(ll a,ll b)
{
    if(a!=0 && b==0)
    {
        return a;
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return(gcd(b,a%b));
    }
    
}

int main()
{
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    ll amin=1e9;
    ll amax=0;
    rep(i,n)
    {
        cin>>a[i];
        amin=min(amin,a[i]);
        amax=max(amax,a[i]);
    }
    if(k>amax)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    ll gnum=a[0];
    for(int i=1;i<n;i++)
    {
        gnum=gcd(gnum,a[i]);
        if(gnum==1)break;
    }

    if(gnum==1)
    {
        cout<<"POSSIBLE"<<endl;
    }
    else
    {
        if((amax-k)%gnum==0)
        {
            cout<<"POSSIBLE"<<endl;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
            
        }
        
    }
    return 0;
    

}
