#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ans += min((arr[i]-arr[i-1])*a, b);
    }
    cout << ans << endl;
    return 0;
}

