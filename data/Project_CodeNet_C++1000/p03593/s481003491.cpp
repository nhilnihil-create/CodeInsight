#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    map<char, int> cnt;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char a;
            cin >> a;
            cnt[a]++;
        }
    }

    int g1 = (H * W) % 2;
    int g2 = (H % 2 == 0 ? 0 : W / 2) + (W % 2 == 0 ? 0 : H / 2);
    int g3 = H * W - g1 - g2;
    for (auto& p : cnt) {
        if (g1 == 0)
            break;
        if (p.second % 4 == 1 || p.second % 4 == 3) {
            p.second--;
            g1--;
        }
    }
    for (auto& p : cnt) {
        if (g2 == 0)
            break;
        if (p.second % 4 == 2) {
            p.second -= 2;
            g2--;
        }
    }
    for (auto& p : cnt) {
        if (g3 == 0)
            break;
        if (p.second % 4 == 0) {
            while (p.second > 0 && g3 > 0) {
                p.second -= 4;
                g3--;
            }
        }
    }
    for (auto& p : cnt) {
        if (p.second != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
