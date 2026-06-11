#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i, 3*n)cin >> a[i];
    vector<ll> s(n+1, 0), t(n+1, 0);
    rep(i, n)s[0] += a[i];
    rep(i, n)t[n] += a[3*n-1-i];

    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, n)que.push(a[i]);
    for(int i = n; i < 2 * n; i++){
        que.push(a[i]);
        s[i-n+1] = s[i-n];
        s[i-n+1] += a[i] - que.top();
        que.pop();
    }
    priority_queue<ll> q;
    rep(i, n)q.push(a[3*n-1-i]);
    for(int i = 2 * n - 1; i >= n; i--){
        q.push(a[i]);
        t[i-n] = t[i-n+1];
        t[i-n] += a[i] - q.top();
        q.pop();
    }
    ll ans = -1001001001001001001;
    rep(i, n+1)ans = max(ans, s[i] - t[i]);
    cout << ans << endl;
}