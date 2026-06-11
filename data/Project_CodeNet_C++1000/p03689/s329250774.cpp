#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s[550];
bool ok[550];

int main() {
    ll H,W,h,w;
    ll cnt = 0;
    cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    bool swp = 0;
    if (W % w == 0) {
        swp = 1;
        swap(W,H);
        swap(w,h);
    }
    int tmp = W;
    cnt = 1;
    while (tmp > 0) {
        s[tmp] = cnt++;
        ok[tmp] = 1;
        tmp -= w;
    }
    tmp = 0;
    cnt = 0;
    while (tmp <= W) {
        s[tmp] = cnt--;
        ok[tmp] = 1;
        tmp += w;
    }
    for (int i = 1; i < W; i++) {
        if (!ok[i]) {
            tmp = i;
            cnt = 0;
            while (tmp <= W) {
                s[tmp] = cnt--;
                ok[tmp] = 1;
                tmp += w;
            }
        }
    }
    cout << "Yes" << endl;
    if (!swp) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << s[j + 1] - s[j] << " \n"[j == W - 1];
            }
        }
    } else {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                cout << s[i + 1] - s[i] << " \n"[j == H - 1];
            }
        }
    }

    return 0;
}
