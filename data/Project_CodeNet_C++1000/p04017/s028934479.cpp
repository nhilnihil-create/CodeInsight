#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, L, Q;
    cin >> N;
    vector<int> x(N);
    rep(i, N) cin >> x[i];
    x.push_back(2e9);
    cin >> L >> Q;
    vector<int> a(Q), b(Q);
    rep(i, Q) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    vector<vector<int>> next(N, vector<int>(17));
    rep(i, N) {
        next[i][0] = upper_bound(x.begin(), x.end(), x[i] + L) - x.begin() - 1;
        //cout << "next[" << i << "][0]=" << next[i][0] << "\n";
    }
    rep(j, 16) {
        rep(i, N) {
            next[i][j + 1] = next[next[i][j]][j];
            //cout << "next[" << i << "][" << j + 1 << "]=" << next[i][j + 1] << "\n";
        }
    }
    rep(i, Q) {
        int ans = 1;
        for (int j = 16; j >= 0; j--) {
            if (next[a[i]][j] >= b[i]) continue;
            ans += 1 << j;
            a[i] = next[a[i]][j];
        }
        cout << ans << "\n";
    }
}