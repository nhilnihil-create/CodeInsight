#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,b,n)for(int i=b;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)
#define all(obj) (obj).begin(),(obj).end()
const int mod=1e9+7;

int main (void){
    ll n,m;
    cin>>n>>m;
    vector<ll>x(n+1),y(m+1);
    REP(i,1,n+1)cin>>x[i];
    REP(i,1,m+1)cin>>y[i];
    ll tx=0,ty=0;
    REP(i,1,n+1)tx+=(2*i-1-n)*x[i];
    REP(i,1,m+1)ty+=(2*i-1-m)*y[i];
    tx%=mod;
    tx*=ty%mod;
    cout<<tx%mod<<endl;
    return 0;

}