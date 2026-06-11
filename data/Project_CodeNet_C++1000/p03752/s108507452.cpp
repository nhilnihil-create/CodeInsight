#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = LONG_LONG_MAX;
    rep(bit, 1<<n) {
        vector<int> cand;
        rep(i, n) {
            if (bit & 1<<i) cand.push_back(i);
        }
        if (int(cand.size())!=k) continue;
        if (cand[0]!=0) continue;
        sort(all(cand));
        ll tmp = 0;
        vector<int> b = a;
        rep(i, k) {
            int cur = cand[i];
            if (cur>0 && b[cand[i-1]]>=b[cur]) {
                tmp += b[cand[i-1]]-b[cur]+1;
                b[cur]=b[cand[i-1]]+1;
            }
            if (i<k-1) {
                FOR(follow, cur+1, cand[i+1]) {
                    if (b[follow]>b[cur]) {
                        tmp += b[follow]-b[cur]+1;
                        b[cur] = b[follow]+1;
                    }
                }
            } else {
                FOR(follow, cur+1, n) {
                    if (b[follow]>b[cur]) {
                        tmp += b[follow]-b[cur]+1;
                        b[cur] = b[follow]+1;
                    }
                }
            }
        }
        // rep(i, k) cout << cand[i] <<((i<k-1)?" ":"\n");
        // rep(i, n) cout << b[i] <<((i<n-1)?" ":"\n");
        // cout << tmp << endl;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}