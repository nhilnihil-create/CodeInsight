#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    vector<int> cnt(26);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cnt[A[i][j] - 'a']++;
        }
    }

    int cnt_1 = (H % 2 == 1 && W % 2 == 1);
    int cnt_4 = (H / 2) * (W / 2);
    int cnt_2 = (H * W - cnt_1 - 4 * cnt_4) / 2;

    for (int i = 0; i < 26; i++) {
        while (cnt[i] >= 4 && cnt_4) {
            cnt[i] -= 4;
            cnt_4--;
        }
        while (cnt[i] >= 2 && cnt_2) {
            cnt[i] -= 2;
            cnt_2--;
        }
        while (cnt[i] >= 1 && cnt_1) {
            cnt[i] -= 1;
            cnt_1--;
        }
    }

    if (cnt_1 == 0 && cnt_2 == 0 && cnt_4 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
