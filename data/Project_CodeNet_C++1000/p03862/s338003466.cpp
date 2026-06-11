#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    
    ll ans=0;
    rep(i,n-1){
        if(a[i]+a[i+1]>x){
            if(a[i]>x){
                ans+=a[i+1];
                ans+=a[i]-x;
                a[i+1]=0;
            }
            else{
                ll tmp=a[i]+a[i+1]-x;
                ans+=tmp;
                a[i+1]-=tmp;
            }
        }
    }

    cout<<ans<<endl;
}