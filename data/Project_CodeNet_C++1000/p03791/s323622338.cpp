#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = ll(1e9+7);

int main(){
    ll n, ans = 1, d = 0;  // d = ロボットiを最初にゴールさせるために必要な先にゴールさせるロボット数
    cin >> n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(ll i=0;i<n;i++){
        ans *= i-d+1;
        ans %= MOD;
        // 後ろのロボットを先にゴールさせるためにはi番目のロボットは少なくともi*2+1にいる必要がある
        d = max(d, ((i*2+1-x[i])+1)/2);
    }
    cout << ans << endl;
    return 0;
}