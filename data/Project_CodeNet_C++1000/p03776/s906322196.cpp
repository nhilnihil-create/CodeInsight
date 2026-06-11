#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(v.rbegin(), v.rend());
    double val = accumulate(v.begin(), v.begin() + a, 0.0) / a;
    printf("%.9lf\n", val);

    unordered_set<ll> nums;
    unordered_map<ll, ll> counter;
    unordered_map<ll, ll> numNeed;
    for (int i = 0; i < n; i++) {
        if (i >= a) {
            if (nums.count(v[i])) {
                counter[v[i]]++;
                continue;
            }
            break;
        }
        counter[v[i]]++;
        numNeed[v[i]]++;
        nums.insert(v[i]);
    }

    vector<vector<ll>> dp(52, vector<ll>(52, 0));
    dp[0][0] = 1;
    for (int i = 1; i < 52; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i - 1][j - 1];
        }
    }
    ll ans = 0;
    int num = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == v[a - 1]) num++;
    }
    if (nums.size() == 1) {
        ll cnt = counter[v[0]];
        for (int i = a; i <= b; i++) {
            ans += dp[cnt][i];
        }
    } else {
        int z = 0;
        for (int i = 0; i < a; i++) {
            if (v[i] == v[a - 1]) z++;
        }
        ans = dp[num][z];
    }
    cout << ans << endl;
}