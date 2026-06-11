#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;

int main() {
    cin >> H >> W;
    int alpha[26];
    memset(alpha, 0, sizeof(alpha));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            alpha[c - 'a']++;
        }
    }

    bool f = true;
    for (int i = 0; i < (H+1)/2; i++) {
        for (int j = 0; j < (W+1)/2; j++) {
            if (i == H/2 && j == W/2) {
                bool check = true;
                for (int k = 0; k < 26; k++) {
                    if (alpha[k] % 2 == 1) {
                        alpha[k]--;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    f = false;
                    break;
                }
            }
            else if (i == H/2 || j == W/2) {
                bool check = true;
                for (int k = 0; k < 26; k++) {
                    if (alpha[k] % 4 == 2) {
                        alpha[k] -= 2;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (int k = 0; k < 26; k++) {
                        if (alpha[k] >= 2) {
                            alpha[k] -= 2;
                            check = false;
                            break;
                        }
                    }
                }
                if (check) {
                    f = false;
                    break;
                }
            }
            else {
                bool check = true;
                for (int k = 0; k < 26; k++) {
                    if (alpha[k] >= 4) {
                        alpha[k] -= 4;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    f = false;
                    break;
                }
            }

        }
        if (!f) break;
    }

    cout << (f ? "Yes" : "No") << endl;

    return 0;
}
