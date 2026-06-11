#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> L(N);
    rep(i, 0, N) cin >> L[i];
    sort(L.begin(), L.end(), greater<ll>());
    ll ans = accumulate(L.begin(), L.begin()+K, 0);
    cout << ans << endl;
    return 0;
}