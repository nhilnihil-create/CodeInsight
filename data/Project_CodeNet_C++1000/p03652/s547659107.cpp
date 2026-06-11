#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ai;
            cin >> ai;
            ai--;
            a.at(i).at(j) = ai;
        }
    }

    vector<int> ptr(n);
    vector<int> removed(m);
    vector<int> cnt(m);
    int ans = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cnt.at(a.at(j).at(ptr.at(j)))++;
        }
        int maximum = 0;
        int max_kind = 0;
        for (int j = 0; j < m; j++) {
            if (maximum < cnt.at(j)) {
                maximum = cnt.at(j);
                max_kind = j;
            }
        }
        ans = min(ans, maximum);

        removed.at(max_kind) = true;
        for (int i = 0; i < n; i++) {
            cnt.at(a.at(i).at(ptr.at(i)))--;
            while (ptr.at(i) < m && removed.at(a.at(i).at(ptr.at(i)))) ptr.at(i)++;
        }
    }

    cout << ans << endl;
}