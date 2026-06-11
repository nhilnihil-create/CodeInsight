//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,sum=0,gsum=0,t; cin>>n;
    k=n*(n+1)/2;
    vector<ll> a(n,0),g(n,0);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    t=sum/k;
    rep(i,n){
        g[i]=a[(i+1)%n]-a[i];
        gsum+=g[i];
    }
    if(sum%k!=0 || gsum!=0) cout<<"NO"<<endl;
    else{
        ll cnt=0;
        rep(i,n){
            ll l=(-g[i]+t)/n,r=(-g[i]+t)%n;
            if(l>=0 && l<=t && r==0) cnt++;
        }
        if(cnt==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}