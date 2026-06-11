#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    long long ans = 0;
    REP(i, N) {
        int sum = a[i - 1] + a[i];
        if (sum > x) {
            ans += sum - x;
            a[i] = max(x - a[i - 1], 0);
        }
    }
    cout << ans << endl;
    return 0;
}
