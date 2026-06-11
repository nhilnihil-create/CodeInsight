//      https://youtu.be/X_hMZYDMps4

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
typedef pair<long long, long long> pll;
const long long inf = 2000000000000000000LL;    // 2e18
#define pi                  acos(-1.0)
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nl                  "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pf                  push_front
#define all(x)              x.begin(),x.end()
#define debug(x)            cout<<"debug "<<x<<"\n"

int main()
{
    fast;
    ll t,i,j,k,l,m,n,o,p,q,temp,ans=0,flag=0,mod=1000000007,odd=0,even=0;
    cin>>n;
    ll v[n+1],a[n+2],b[n+2];
    for(i=1;i<=n;i++){
        cin>>v[i];
        a[i]=0;
        b[i]=0;
    }
    for(i=n,temp=n;i>0;i--,temp--){
        b[1]+=temp;
        b[v[i]+1]-=temp;
        a[1]-=(temp);
        a[v[i]]+=(temp);
    }
    //cout<<a[1]<<" "<<b[1]<<nl;
    for(i=2;i<=n;i++){
        //cout<<a[i]<<" "<<b[i]<<nl;
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for(i=1;i<=n;i++) cout<<a[i]+((n*n)+10)<<" ";
    cout<<nl;
    for(i=1;i<=n;i++) cout<<b[i]<<" ";
}
