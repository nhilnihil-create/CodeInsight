#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;


int main() {
    int n, m; cin >> n >> m;
    vector<int> x(n); rep(i, n) cin >> x[i];
    sort(x.begin(), x.end());
    vector<vector<int>> y(m);
    rep(i, n) {
        y[x[i] % m].push_back(x[i]);
    }
    vector<int> cnt(m);
    rep(i, n-1) {
        if (x[i+1] == x[i]) {
            cnt[x[i]%m]++;
            i++;
        }
    }
    int ans = 0;
    rep(i, m) {
        int p1 = i;
        int p2 = (m - i) % m;
        if (p2 < p1) continue;
        // 0 の時も m/2 も対応できるので。m=1でやられないためにも下手な場合わけをしない。
        if (p2 == p1) {
            ans += y[p1].size() / 2;
            continue;
        }
        int n1 = y[p1].size();
        int n2 = y[p2].size();
        if (n1 < n2) {
            swap(p1, p2);
            swap(n1, n2);
        }

        if (2 * cnt[p1] >= n1 - n2) {
            ans += (n1 + n2) / 2;
        } else {
            ans += cnt[p1] + n2;
        }
    }

    cout << ans << endl;

    return 0;
}


    
