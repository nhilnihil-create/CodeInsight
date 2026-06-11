#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll W;
    cin >> N >> W;

    vector<ll> w(N);
    vector<ll> v(N);

    for(int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<map<ll, ll> > dp(N);

    dp[0][0] = 0;
    dp[0][w[0]] = v[0];

    for(int i = 1; i < N; i++) {
        for(auto j = begin(dp[i - 1]); j != dp[i - 1].end(); j++) {
            ll x = j -> first;
            ll y = j -> second;
            dp[i][x] = max(dp[i][x], y);
            dp[i][x + w[i]] = max(dp[i][x + w[i]], y + v[i]);
        }
    }

    ll ans = 0;

    for(auto i = begin(dp[N - 1]); i != dp[N - 1].end(); i++) {
        if(i -> first > W) break;
        ans = max(ans, i -> second);
        cerr << i -> first << " " << i -> second << endl;
    }

    cout << ans << endl;
}