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
    ll n,m,ans=1; cin>>n>>m;
    if(abs(n-m)>1) cout<<0<<endl;
    else if(abs(n-m)==1){
        rep(i,n) ans=(ans*(i+1))%MOD;
        rep(i,m) ans=(ans*(i+1))%MOD;
        cout<<ans<<endl;
    }
    else{
        rep(i,n) ans=(ans*(i+1))%MOD;
        rep(i,m) ans=(ans*(i+1))%MOD;
        cout<<(ans*2)%MOD<<endl;
    }
}
