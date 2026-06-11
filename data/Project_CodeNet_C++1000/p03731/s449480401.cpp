#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int64_t ans = t;
    int pre;
    cin >> pre;
    for (int i = 0; i < n-1; i++) {
        int ti;
        cin >> ti;
        ans += min(ti - pre, t);
        pre = ti;
    }
    cout << ans << endl;
} 
