#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, x;
    cin >> N >> x;

    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];

    ll ans = 0;
    rep(i, 0, N-1){
        ll sum = a[i] + a[i+1];
        ll diff = sum - x;
        if(diff > 0){
            if(a[i+1] >= diff){
                a[i+1] -= diff;
                ans += diff;
            }else{
                a[i] -= (diff - a[i+1]);
                a[i+1] = 0;
                ans += diff;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}