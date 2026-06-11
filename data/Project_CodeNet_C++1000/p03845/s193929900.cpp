#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, m = 0;
    vector<int> t, constt;
    vector<int> p;
    vector<int> x;
    cin >> n;

    int temp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        t.push_back(temp);
        constt.push_back(temp);
    }
    cin >> m;

    int tempp = 0, tempx = 0;
    for (int i = 0; i < m; ++i) {
        cin >> tempp >> tempx;
        p.push_back(tempp);
        x.push_back(tempx);
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (j == p[i] - 1) {
                t[j] = x[i];
            }
            ans += t[j];
        }
        cout << ans << endl;
        for (int k = 0; k < t.size(); ++k) {
            t[k] = constt[k];
        }
        ans = 0;
    }
}