#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    // dp[k][i]i番目のホテルから2^k日で到達可能な最右のホテル
    vector<vector<int>> dp(20, vector<int>(n, 0));
    for(size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l;
    cin >> l;
    for(size_t i = 0; i < n; i++) {
        auto itr = lower_bound(all(a), a[i] + l + 1) - a.begin();
        dp[0][i] = itr - 1;
    }
    for(int k = 0; k < 19; k++) {
        for(int i = 0; i < n; i++) {
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(x > y) {
            swap(x, y);
        }
        int day = 0;
        for(int i = 19; i >= 0; i--) {
            if(dp[i][x] < y) {
                x = dp[i][x];
                day += 1 << i;
            }
        }
        cout << day + 1 << endl;
    }
}
