#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;


int main() {
    int N,x; cin>>N>>x;
    vector<ll> a(N);

    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    //vector<ll> t(N,0);

    vector<ll> mini(N);
    ll ans=0ll;
    for (int i = 0; i < N; ++i) {
        mini[i]=a[i];
        ans+=mini[i];
    }
    //cout<<ans<<endl;
    for (int i = 1; i < N; ++i) { //i:何回変色させるか
        ll tmp=0ll;
        for (int j = 0; j < N; ++j) {
            int ref=j-i;
            if(ref<0) ref=N+ref;
            mini[j]=min(mini[j],a[ref]);
            //if(i==1) cout<<ref<<" "<<mini[j]<<endl;
            tmp+=mini[j];
        }
        ans=min(ans,tmp+(ll)x*i);

    }

    cout<<ans<<endl;

    return 0;
}