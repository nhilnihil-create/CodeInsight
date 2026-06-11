#include <bits/stdc++.h>

using namespace std;


int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            ans.emplace_back(i);
        }
    }

    for (int i = 0; i < H; ++i) {
        if (i % 2 == 1) {
            reverse(ans.begin() + i * W, ans.begin() + (i + 1) * W);
        }
    }

    int cnt = 0;
    for (auto x:ans) {
        cout << x;
        cnt++;
        if (cnt % W == 0) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}

