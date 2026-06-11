#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(3 * N);
    rep(i, 3 * N) cin >> a[i];
    
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    rep(i, N) {
        ans += a[2 * i + 1];
    }
    cout << ans << endl;
    return 0;
}
