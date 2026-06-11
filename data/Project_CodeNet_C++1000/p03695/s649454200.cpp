#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll>col(9,0);
    for(ll i=0;i<n;i++){
        ll x=0;
        while(a[i]>=400){
            a[i]-=400;
            x++;
            if(x>=8){
                break;
            }
        }
        col[x]++;
    }
    ll ans_min=0;
    for(ll i=0;i<8;i++){
        if(col[i]>0){
            ans_min++;
        }
    }
    ll ans_max=ans_min;
    ans_max+=(col[8]);
    if(ans_min==0) ans_min++;
    cout << ans_min << " " << ans_max << endl;
}