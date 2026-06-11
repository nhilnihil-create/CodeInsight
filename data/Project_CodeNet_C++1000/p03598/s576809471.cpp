#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
 
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N);
    rep(i, 0, N) cin >> x[i];
    ll ans = 0;
    rep(i, 0, N){
        ans += 2*min(x[i], K-x[i]);
    }
    cout << ans << endl;
    return 0;
}