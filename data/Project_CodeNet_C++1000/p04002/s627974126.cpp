#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

ll H, W, N;
map<pii,ll> mp;
ll ans[10] = {};

void solve() {
    cin >> H >> W >> N;
    rep(i,N) {
        int a, b;
        cin >> a >> b;
        for (int j = a-1; j <= a+1; j++) {
            for (int k = b-1; k <= b+1; k++) {
                mp[pii(j, k)]++;
                //cout << mp[pii(j, k)] << endl;
            }
        }
    }
    ll sum = 0;
    for (auto p : mp) {
        int y = p.first.first;
        int x = p.first.second;
        int c = p.second;
        if (y >= 2 && y <= H-1 && x >= 2 && x <= W-1) {
            ans[c]++;
            sum++;
        }
    }
    ans[0] = (H-2) * (W-2) - sum;
    rep(i,10) cout << ans[i] << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
