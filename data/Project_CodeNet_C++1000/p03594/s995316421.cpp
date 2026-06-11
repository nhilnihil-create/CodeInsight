#include <bits/stdc++.h>
using namespace std;
int main()
{
    int H, W, d; cin >> H >> W >> d;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << "RYGB"[((i - j + 1000) / d) % 2 * 2 + (i + j) / d % 2];
        }
        cout << '\n';
    }
    return 0;
}