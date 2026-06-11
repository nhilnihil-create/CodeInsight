#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int64_t H, W;
    cin >> H >> W;
    if(H%3 == 0 || W%3 == 0) {
        cout << 0 << endl;
    } else {
        int64_t ans = INT64_MAX;
        for(int64_t i=1; i<H; i++) {
            int64_t S1 = i*W;
            int64_t S2 = (H-i) * (W/2);
            int64_t S3 = H*W - S1 - S2;
            ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
        }
        for(int64_t j=1; j<W; j++) {
            int64_t S1 = j*H;
            int64_t S2 = (W-j) * (H/2);
            int64_t S3 = H*W - S1 - S2;
            ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
        }
        ans = min(ans, H);
        ans = min(ans, W);
        cout << ans << endl;
    }
    return 0;
}
