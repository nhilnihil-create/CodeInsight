# include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a[n];
    for (int i = 0; i < n; i++) a[i] = vector<int>(m, 0);
    for (int i = 0; i < n; i++) for (int k = 0; k < m; k++) cin >> a[i][k];
    int ans = -1;
    vector<int> play(m+1, 1);
    for (int i = 0; i < m-1; i++) {
        vector<int> tops(n);
        for (int k = 0; k < n; k++) {
            int t;
            for (int l = 0; l < n; l++) {
                if (play[a[k][l]]) {
                    t = a[k][l];
                    break;
                }
            }
            tops[k] = t;
        }
        sort(tops.begin(), tops.end());
        int cur = 1;
        int maxCon = 0;
        vector<int> maxVals;
        for (int k = 1; k < n; k++) {
            if (k == n-1) {
                if (tops[k] == tops[k-1]) {
                    cur++;
                    if (maxCon < cur) {
                        maxCon = cur;
                        maxVals.clear();
                        maxVals.push_back(tops[k]);
                    } else if (maxCon == cur) {
                        maxVals.push_back(tops[k]);
                    }
                } else {
                    if (maxCon < cur) {
                        maxCon = cur;
                        maxVals.clear();
                        maxVals.push_back(tops[k-1]);
                    } else if (maxCon == cur) {
                        maxVals.push_back(tops[k-1]);
                        if (maxCon == 1) maxVals.push_back(tops[k]);
                    }
                }
            }
            if (tops[k] == tops[k-1]) {
                cur++;
            } else {
                if (maxCon < cur) {
                    maxCon = cur;
                    maxVals.clear();
                    maxVals.push_back(tops[k-1]);
                } else if (maxCon == cur) {
                    maxVals.push_back(tops[k-1]);
                }
                cur = 1;
            }
        }
        for (int k = 0; k < n; k++) {
            for (auto &mv : maxVals) {
                play[mv] = 0;
            }
        }
        if (ans < 0) ans = maxCon;
        else ans = min(ans, maxCon);
    }
    if (ans < 0) cout << n << endl;
    else cout << ans << endl;
    return 0;
}
