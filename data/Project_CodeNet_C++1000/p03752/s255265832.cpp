#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto i = 0; i < n; i++) cin >> a[i];

    int64_t ans = INT64_MAX;
    for (auto i = 0; i < (1 << n); i++) {
        if((int)bitset<16>(i).count() != k) continue;
        int64_t tmp = 0;
        int64_t prev_height = a[0];
        for (auto j = 1; j < n; j++) {
            if(i & (1 << j)) {
                if(prev_height + 1 < a[j]) prev_height = a[j];
                else {
                    prev_height++;
                    tmp += prev_height - a[j];
                }
            }
            else prev_height = max(prev_height, (int64_t)a[j]);
        }
        // cout << bitset<15>(i) << " " << tmp << " " << ans << endl;
        ans = min(ans, tmp);
    }


    cout << ans << endl;
    return 0;
}