#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007,INF=1001001001;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


#define int ll
int n,a,b;
int h[100010];


signed main(){
    cin>>n>>a>>b;a-=b;
    rep(i,0,n)cin>>h[i];
    
    int l=0,r=INF;
    while(l+1<r){
        ll c=(r+l)>>1;
        ll t=0;
        rep(i,0,n){
            ll x=max(h[i]-c*b,0LL);
            ll s=(x+a-1)/a;
            t+=s;
        }
        if(t<=c)r=c;
        else l=c;
    }
    
    
    cout<<r<<endl;
    return 0;
}