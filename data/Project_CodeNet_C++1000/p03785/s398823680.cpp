#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> arr(n, 0);
    for(auto& val: arr) {
        cin >> val;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0, last = -1e9;
    ll used = 0;
    for(int i = 0; i < n; i++) {
        if (used >= c || arr[i]-last > k) {
            ans += 1;
            last = arr[i];
            used = 1;
        } else {
            used += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
