#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int64_t H, W;
    cin >> H >> W;
    int64_t ans = min(H, W);
    if (H % 3 == 0|| W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int64_t i = 1; i < W + 1; i++){
        ans = min(ans, max((H + 1) / 2 * i, (W - i) * H) - min(H / 2 * i, (W - i) * H));
    }
    for(int64_t i = 1; i < H + 1; i++){
        ans = min(ans, max((W + 1) / 2 * i, (H - i) * W) - min(W / 2 * i, (H - i) * W));
    }
    cout << ans << endl;
}
