#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    int cnt1 = H * W % 2;
    int cnt4 = (H / 2) * (W / 2);
    int cnt2 = (H * W - 4 * cnt4 - cnt1) / 2;

    unordered_map<char, int> map;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            map[A[i][j]]++;
        }
    }

    for (auto p : map) {
        while (p.second / 4 && cnt4) {
            p.second -= 4;
            cnt4--;
        }
        while (p.second / 2 && cnt2) {
            p.second -= 2;
            cnt2--;
        }
        while (p.second && cnt1) {
            p.second -= 1;
            cnt1--;
        }
    }

    if (cnt1 == 0 && cnt2 == 0 && cnt4 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}