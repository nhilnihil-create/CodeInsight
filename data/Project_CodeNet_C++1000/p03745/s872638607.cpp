#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        if (ai != cur) {
            a.push_back(ai);
            cur = ai;
        }
    }
    int ans = 1;
    int dir = -1;
    for (int i = 1; i < (int)a.size(); ++i) {
        if (dir < 0) {
            if (a[i] > a[i - 1]) {
                dir = 1;
            } else {
                dir = 0;
            }
        } else {
            if (dir) {
                if (a[i] < a[i - 1]) {
                    ++ans;
                    dir = -1;
                }
            } else {
                if (a[i] > a[i - 1]) {
                    ++ans;
                    dir = -1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
