#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ll> t(n),a(n);
    rep(i,0,n) cin>>t[i];
    rep(i,0,n) cin>>a[i];
    
    vector<ll> kakutei_t(n),kakutei_a(n);
    int now=-1;
    rep(i,0,n){
        if(t[i]!=now){
            now=t[i];
            kakutei_t[i]=now;
        }
        else kakutei_t[i]=0;
    }
    
    now=-1;
    rrep(i,n,0){
        if(a[i]!=now){
            now=a[i];
            kakutei_a[i]=now;
        }
        else kakutei_a[i]=0;
    }
    
    rep(i,0,n){
        if(kakutei_t[i]!=0 && kakutei_a[i]!=0 && kakutei_t[i]!=kakutei_a[i]){
            cout<<0<<endl;
            return 0;
        }
        if(kakutei_t[i]!=0 && kakutei_a[i]==0 && a[i]<t[i]){
            cout<<0<<endl;
            return 0;
        }
        if(kakutei_a[i]!=0 && kakutei_t[i]==0 && t[i]<a[i]){
            cout<<0<<endl;
            return 0;
        }
    }
    
    rep(i,0,n){
        if(kakutei_t[i]!=0) t[i]=1;
        if(kakutei_a[i]!=0) a[i]=1;
    }
    
    
    ll ans=1;
    rep(i,0,n){
        ans*=min(a[i],t[i]);
        ans%=MOD;
    }
    
    cout<<ans<<endl;
    
}

