#include "bits/stdc++.h"
using namespace std;

void solve() {
        long long n;
        cin >> n;
        vector<int> p;
        int m;
        for (m = 40; m > 0; m --) if (n >= (1LL << m) - 1) break;
        n -= (1LL << m) - 1;
        for (int i = 1; i <= m; i ++) p.push_back(i);
        for (int i = m - 1; i >= 0; i --) {
                if (n < (1LL << i)) continue;
                m ++;
                p.insert(p.begin() + i, m);
                n -= (1LL << i);
        }
        for (int i = 1; i <= m; i ++) p.push_back(i);
        cout << p.size() << endl;
        for (int i = 0; i < 2 * m; i ++) cout << p[i] << (i == 2 * m - 1 ? '\n' : ' ');
        return;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        //int T;
        //freopen("a.in", "r", stdin);
        //cin >> T;
        //while (T --) solve();
        
        solve();
        return 0;
}

