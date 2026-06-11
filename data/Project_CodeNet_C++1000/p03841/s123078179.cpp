#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n + 1), ans(n * n + 1), cnt(n + 1), dnt(n + 1), ord;
    vector<pair<int, int>> tmp;
    rep(i, 1, n + 1) {
        cin >> x[i];
        ans[x[i]] = i;
        cnt[i] = i - 1;
        dnt[i] = n - i;
        tmp.emplace_back(x[i], i);
    }
    sort(tmp.begin(), tmp.end());
    rep(i, 0, n) ord.emplace_back(tmp[i].second);
    int k = 0;
    bool used = false;
    rep(i, 1, n * n + 1) {
        debug(i);
        if (ans[i] != 0) {
            if (cnt[ans[i]] == 0 && dnt[ans[i]] == n - ans[i]) continue;
            debug(ans);
            debug(cnt[ans[i]], dnt[ans[i]]);
            cout << "No" << endl;
            return 0;
        } else if (!used) {
            while (k != n && cnt[ord[k]] == 0) {
                k++;
            }
            if (k == n) {
                used = true;
                k = 0;
                if (dnt[ord[0]] == 0) k = 1;
                debug(k);
                ans[i] = ord[k];
                dnt[ord[k]]--;
                continue;
            }
            ans[i] = ord[k];
            cnt[ord[k]]--;
        } else {
            while (k != n && dnt[ord[k]] == 0) {
                k++;
            }
            ans[i] = ord[k];
            dnt[ord[k]]--;
        }
    }
    cout << "Yes" << endl;
    rep(i, 1, n * n + 1) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}