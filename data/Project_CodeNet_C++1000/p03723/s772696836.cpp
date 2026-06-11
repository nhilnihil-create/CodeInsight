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
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll>pa(2),pb(2),pc(2);
    if(a%2!=0 || b%2!=0 || c%2!=0)
    {
        cout<<0;
        return 0;
    }
    pa[0]=a,pb[0]=b,pc[0]=c;
    if((b+c)%2!=0 || (a+c)%2!=0 || (a+b)%2!=0)
    {
        cout<<1;
        return 0;
    }
    pa[1]=(b+c)/2;
    pb[1]=(a+c)/2;
    pc[1]=(a+b)/2;
    ll count=1;
    while(1)
    {
        ll ta,tb,tc;
        ta=pa[0]+pa[1];
        tb=pb[0]+pb[1];
        tc=pc[0]+pc[1];
        if(ta%2!=0 || tb%2!=0 || tc%2!=0)
        {
            break;
        }
        ta/=2,tb/=2,tc/=2;
        if(ta==pa[0] && tb==pb[0] && tc==pc[0])
        {
            count=-1;
            break;
        }
        count++;
        pa[0]=pa[1];
        pb[0]=pb[1];
        pc[0]=pc[1];
        pa[1]=ta;
        pb[1]=tb;
        pb[1]=tb;
    }
    cout<<count;
}
