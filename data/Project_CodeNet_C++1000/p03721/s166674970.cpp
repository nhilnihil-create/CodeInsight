#include <bits/stdc++.h>
using namespace std;

static const int AMAX = 100000;
int64_t cnt[AMAX + 1];

int main(void){
    int n;
    int64_t k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a] += b;
    }
    
    for (int ans = 1; ans <= AMAX; ans++) {
        if (k <= cnt[ans]) {
            cout << ans << "\n";
            break;
        }
        k -= cnt[ans];
    }
    return 0;
}
