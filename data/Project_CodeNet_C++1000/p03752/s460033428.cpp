#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> h(n);

    ll ans = 1e+15;
    rep(i,n){
        cin>>h[i];
    }

    for(int bit=0;bit<(1<<n);bit++){
        vector<ll> ht(n);
        copy(h.begin(),h.end(),ht.begin());
        
        int t = bit;
        ll mx=0;
        ll cost=0;
        int cnt=0;
        rep(i,n){
            if(t&1){
                if(mx>=ht[i]){
                    cost += mx+1-ht[i];
                    ht[i]=mx+1;
                }
            }
            if(ht[i]>mx){
                mx = ht[i];
                cnt++;
            }
            t>>=1;
        }
        if(cnt>=k){
            ans = min(cost,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}