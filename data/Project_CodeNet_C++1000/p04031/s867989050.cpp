#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    int ans = 1e9;
    for (int i = -100; i <= 100; ++i) {
        int res = 0;
        rep(j, N) res += (a[j] - i) * (a[j] - i);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
