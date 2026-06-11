#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N,K; cin>>N>>K;

    vector<ll> a(N);

    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    vector<ll> ruiseki(N+1,0ll),ruisekip(N+1,0ll);

    for (int i = 0; i < N; ++i) {
        ruiseki[i+1]=ruiseki[i]+a[i];
        ruisekip[i+1]=ruisekip[i]+max(a[i],0ll);
    }

    ll psum=ruisekip[N];
    ll ans=0ll;
    //last black
    for (int i = 0; i <= N - K; ++i) {
        ll tmp=ruisekip[i]-ruisekip[i+K];
        tmp+=ruiseki[i+K]-ruiseki[i];
        ans=max(ans,psum+tmp);
    }

    //last white
    for (int i = 0; i < N - K; ++i) {
        ll tmp=ruisekip[i+K]-ruisekip[i];
        ans=max(ans,psum-tmp);
    }

    cout<<ans<<endl;

    return 0;
}
