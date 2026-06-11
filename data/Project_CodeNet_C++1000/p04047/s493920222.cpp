#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(2 * N);
    rep(i, 2 * N) cin >> L[i];
    sort(L.begin(), L.end());
    int ans = 0;
    rep(i, N) ans += L[2 * i];
    cout << ans << endl;
    return 0;
}
