#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main() {
    int n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,n){
        cin>>a[i];
    }
    if(k==1){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1LL<<60;
    for(int bit=0;bit<(1<<n);bit++){
        if(__builtin_popcount(bit)==k-1 && !(bit & 1<<0)){
            ll cur=a[0],tmp=0;
            rep(i,n){
                if(bit & (1<<i)){
                    ll add=max(0LL,cur-a[i]+1);
                    tmp+=add;
                    cur=a[i]+add;
                }
                else cur=max(cur,a[i]);
            }
            //cout<<bit<<" "<<tmp<<endl;
            ans=min(ans,tmp);
        }
    }
 
    cout<<ans<<endl;
}


