#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N; cin>>N;
    vector<ll> t(N+2,0),a(N+2,0);
    for (int i = 1; i <= N; ++i) {
        cin>>t[i];
    }

    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
    }

    ll ans=1ll;

    for (int i = 1; i <= N; ++i) {
        if(t[i]>t[i-1]){
            if(a[i]<t[i]){
                cout<<0<<endl;
                return 0;
            }
        }else if(a[i]>a[i+1]){
            if(t[i]<a[i]){
                cout<<0<<endl;
                return 0;
            }
        }else{
            (ans*=min(a[i],t[i]))%=MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}
