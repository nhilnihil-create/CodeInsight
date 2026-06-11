#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n, 0);
    for(ll& val: arr)
        cin >> val;
    ll ans = 0;
    ll acc = 0, acc2 = 0;
    vector<ll> dp(n+1, 0);
    vector<ll> exclude(n+1, 0);
    for(int i = 0; i < n; i++) {
        acc += arr[i];
        dp[i+1] = acc;
        acc2 += max(0LL, arr[i]);
        exclude[i+1] = acc2;
    }
    for(int i = k; i < dp.size(); i++) {
        ll exc = acc2 - (exclude[i]-exclude[i-k]);
        ans = max(ans, exc+max(dp[i]-dp[i-k], 0LL));
    }
    cout << ans << endl;
    return 0;
}


