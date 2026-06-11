#include <iostream>
#include <algorithm>

using namespace std;

int cls[15];

void solve() {
    int n;
    int cnt=0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int ai;
        cin >> ai;
        if (ai >= 3200)
            ++cnt;
        else
            ++cls[ai/400];
    }
    int ans = 0;
    for (int r: cls)
        if (r)
            ++ans;
    if (ans == 0) {
        ans = 1;
        --cnt;
    }
    cout << ans << " " << (ans + cnt);

}

int main() {

	solve();
    return 0;
}
