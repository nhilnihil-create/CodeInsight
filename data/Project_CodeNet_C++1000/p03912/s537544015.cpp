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
    ans += y[0].size() / 2;
    for (int i = 1; i < m/2; i++) {
        int p1 = i;
        int p2 = m - i;
        int n1 = y[p1].size();
        int n2 = y[p2].size();
        if (n1 < n2) {
            swap(p1, p2);
            swap(n1, n2);
        }

        if (n1 == n2) ans += n1;
        else {
            ans += n2;
            ans += min(cnt[p1], (n1-n2) / 2);
        }
    }
    if (m/2 == 0) {
        cout << ans << endl;
        return 0;
    }
    
    if (m % 2 == 0) ans += y[m/2].size() /2;
    else {
        int p1 = m / 2;
        int p2 = m - p1;
        int n1 = y[p1].size();
        int n2 = y[p2].size();
        if (n1 < n2) {
            swap(p1, p2);
            swap(n1, n2);
        }

        if (n1 == n2) ans += n1;
        else {
            ans += n2;
            ans += min(cnt[p1], (n1-n2) / 2);
        }
    }
    cout << ans << endl;

    return 0;
}


    
