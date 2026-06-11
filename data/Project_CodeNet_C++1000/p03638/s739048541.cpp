#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            ans.emplace_back(i + 1);
        }
    }
    for (int i = 0; i < h; ++i) {
        vector<int> now;
        for (int j = 0; j < w; ++j) {
            now.emplace_back(ans[i * w + j]);
        }
        if (i % 2 == 1) reverse(now.begin(), now.end());
        for (int k : now) {
            cout << k << " ";
        }
        cout << endl;
    }
}
