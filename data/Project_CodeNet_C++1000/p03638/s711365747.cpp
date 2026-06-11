#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

int main() {
    long long n, h, w;
    cin >> h >> w >> n;
    vector<long long> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    vector<long long> wall(h, w);
    vector<vector<int>> ans(h);
    int now = 0;
    REP(i, n) {
        for (int j = 0; j < as[i]; j++) {
            ans[now].push_back(i + 1);
            wall[now]--;
            if (wall[now] == 0) {
                now++;
            }
        }
    }
    REP(i, h) {
        if (i % 2 == 1) {
            reverse(ans[i].begin(), ans[i].end());
        }
    }
    REP(i, h) {
        REP(j, w) { cout << ans[i][j] << " "; }
        cout << endl;
    }
}