// AtCoder template
// sabaより胡蝶しのぶさんの方が可愛いのではないか？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k; cin >> n >> k;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    vector<ll> amaxh(n+1);
    amaxh[0] = 0LL;
    rep(i,n) amaxh[i+1] = max(a[i], amaxh[i]);
    ll ans = 1e18;
    for(int bit = 0; bit < (1 << n); ++bit){
        if(__builtin_popcount(bit) != k) continue;

        ll nowh = 0LL, tmp = 0LL;
        rep(i,n){
            if(bit & (1 << i)){
                nowh = max(nowh, amaxh[i]);
                if(nowh >= a[i]){
                    tmp += nowh - a[i] + 1;
                    nowh++;
                }else nowh = a[i];
            }
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}