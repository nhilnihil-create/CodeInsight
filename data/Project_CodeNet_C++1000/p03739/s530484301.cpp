#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];

    ll cnt1,cnt2;
    cnt1 = cnt2 = 0;
    ll sum = 0;

    //最初が正の時
    for(ll i=0; i<n; i++){
        sum += a[i];
        if(i%2 == 0 && sum <= 0){
            cnt1 += abs(sum-1);
            sum = 1;
        }

        else if(i%2 != 0 && sum >= 0){
            cnt1 += sum+1;
            sum = -1;
        }
    }
    sum = 0;

    //最初が負の時
    for(ll i=0; i<n; i++){
        sum += a[i];
        if(i%2 == 0 && sum >= 0){
            cnt2 += sum+1;
            sum = -1;
        }
        
        if(i%2 != 0 && sum <= 0){
            cnt2 += abs(sum-1);
            sum = 1;
        }
    }

    ll ans = min(cnt1,cnt2);

    cout<<ans<<endl;

    return 0;
}