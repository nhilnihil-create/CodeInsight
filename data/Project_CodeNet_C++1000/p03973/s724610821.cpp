#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    LL ans = 0;
    int mi = 1;
    for (int i = 1; i <= N; ++i) {
        int t; cin >> t;
        if (t < mi) {
            continue;
        } else if (t == mi) {
            ++mi;
            continue;
        }
        ans += (t-1)/mi;
        if (i == 1)  mi = 2;
    }
    cout << ans << endl;
    return 0;
}
