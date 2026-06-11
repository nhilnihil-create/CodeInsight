#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<vector<int>> g(m);
    vector<int> cnt(m);
    for (auto x: mp) {
        g.at(x.first % m).push_back(x.second);
        cnt.at(x.first % m) += x.second;
    }

    int ans = 0;
    for (int i = 0; i <= m / 2; i++) {
        if (i == 0 || (i == m - i)) ans += cnt.at(i) / 2;
        else {
            vector<int> *s;
            int cnt_s, cnt_t;
            if (cnt.at(i) > cnt.at(m - i)) {
                s = &g.at(i);
                cnt_s = cnt.at(i);
                cnt_t = cnt.at(m - i);
            }
            else {
                s = &g.at(m - i);
                cnt_s = cnt.at(m - i);
                cnt_t = cnt.at(i);
            }
            
            for (int j = 0; j < (int)s -> size(); j++) {
                if (cnt_s > cnt_t) {
                    int c = min(s -> at(j) / 2, (cnt_s - cnt_t) / 2);
                    ans += c;
                    cnt_s -= c * 2;
                }
            }
            ans += cnt_t;
        }
    }
    cout << ans << endl;
}