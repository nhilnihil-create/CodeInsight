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
    ll x,n;
    cin>>n>>x;
    cout<<3*(n-gcd(n,x));
}
