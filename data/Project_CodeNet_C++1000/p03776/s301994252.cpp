#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

ll nCr(ll n, ll m) {
    // cout << n << " - " << m << endl;
    m = min(m, n-m);
    if (m == 0) return 1;
    ll num = 1, dem = 1;
    for(ll i = 1; i <= m; i++) {
        num = (num*(n+1-i));
        num = num / i;
    }
    return num;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    unordered_map<ll, int> cnt;
    vector<ll> arr(n, 0);
    for(auto& val: arr) {
        cin >> val;
        cnt[val] += 1;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    ll S = accumulate(arr.begin(), arr.begin()+a, 0LL);
    cout << fixed << setprecision(12) << double(S)/double(a) << endl;
    int larger_cnt = 0;
    for(int i = 0; i < n; i++)
        if (arr[i] > arr[a-1])
            larger_cnt += 1;
    ll ans = 0, last = arr[a-1];
    if (arr[a-1] == arr[0]) {
        for(int k = a; k <= b && arr[k-1] == last; k++) {
            ans += nCr(cnt[last], k-larger_cnt);
        }
        cout << ans << endl;
    } else {
        cout << nCr(cnt[last], a-larger_cnt) << endl;
    }
    return 0;
}


