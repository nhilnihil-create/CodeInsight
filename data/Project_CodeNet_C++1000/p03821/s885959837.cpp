#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];

    ll ans=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=ans;
        if(a[i]%b[i]==0) continue;
        if(a[i]<b[i]) ans+=b[i]-a[i];
        else if(a[i]>b[i]) ans+=b[i]*((a[i]+b[i]-1)/b[i])-a[i];
        //cout<<ans<<endl;
    }

    cout<<ans<<endl;
}
