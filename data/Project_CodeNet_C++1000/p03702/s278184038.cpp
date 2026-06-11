#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;


int main(){
    ll N,A,B; cin>>N>>A>>B;

    vector<ll> h(N);
    for (ll i = 0ll; i < N; ++i) {
        cin>>h[i];
    }
    sort(h.rbegin(),h.rend());
    ll maxi=h[0]/B+1,mini=h[0]/A-1;
    ll x=(maxi+mini)/2;
    while(maxi-mini>1ll){
        //printf("%d %d %d\n",maxi,mini,x);
        ll cnt=0ll;
        for (ll i = 0ll; i < N; ++i) {
            cnt+=max(0ll,(ll)ceil((double)(h[i]-B*x)/(A-B)));
        }
        if(cnt>x){
            ll mid=(x+maxi)/2;
            mini=x; x=mid;
        }else{
            ll mid=(x+mini)/2;
            maxi=x; x=mid;
        }
    }
	
    cout<<maxi<<endl;

    return 0;
}