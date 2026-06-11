#include "bits/stdc++.h"
using namespace std;

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(m);
        int odd = 0;
        vector<bool> f(m, false);
        int p[2];
        p[0] = -1, p[1] = -1;
        int k = 0;
        for (int i = 0; i < m; i ++) {
                scanf("%d", &a[i]);
                if (a[i] & 1) {
                        if (odd > 1) return !puts("Impossible");
                        p[k ++] = i;
                        odd ++;
                }
        }
        if (odd > 0) if (p[0] != 0) swap(a[p[0]], a[0]);
        if (odd > 1) if (p[1] != m - 1) swap(a[p[1]], a[m - 1]);
        for (int i = 0; i < m; i ++) cout << a[i] << (i == m - 1 ? '\n' : ' ');
        vector<int> ans;
        if (m == 1) {
                if (a[0] > 1) ans.push_back(a[0] - 1);
                ans.push_back(1);
        } else {
                if (a[0] != 1) ans.push_back(a[0] - 1);
                for (int i = 1; i < m - 1; i ++) {
                        ans.push_back(a[i]);
                }
                ans.push_back(a[m - 1] + 1);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        return 0;
}

