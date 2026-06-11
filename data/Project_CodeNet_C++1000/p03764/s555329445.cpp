#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=LLONG_MAX;
const int inf=INT_MAX;
const int nmax=1e5+5;
const int mod=1e9+7;
using namespace std; 
int n,m,i;
ll x,totx,toty;
int main()
{
    //freopen("sol.in","r",stdin);
    //freopen("sol.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	totx+=x*(i-(n-i-1));
    	totx%=mod;
    }
    for(i=0;i<m;i++)
    {
    	cin>>x;
    	toty+=x*(i-(m-i-1));
    	toty%=mod;
    }
    cout<<(totx*toty)%mod<<endl;
    return 0;
}