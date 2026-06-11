#include<bits/stdc++.h>
using namespace std;

bool alltrue(vector<bool> &a) {
    bool b = true;
    for (auto A : a) if (A != b) return false;
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        bool flag = false;
        vector<bool> blist(m, false);
        while (!alltrue(blist)) {
            bool tmp = true;
            vector<int> cnt(m, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!blist[A[i][j] - 1]) {
                        cnt[A[i][j] - 1]++;
                        break;
                    }
                }
            }

            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, cnt[i]);
                if (cnt[i] > mid) blist[i] = true;
            }

            if (mx <= mid) {
                flag = true;
                break;
            }
        }
        if (flag) r = mid;
        else l = mid;
    }
    cout << r << endl;
}