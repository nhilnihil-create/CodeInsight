#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> t(N);
    rep(i, N) cin >> t[i];
    long long ans = T;
    rep(i, N - 1) {
        if (t[i] + T < t[i + 1]) ans += T;
        else ans += t[i + 1] - t[i];
    }
    cout << ans << "\n";
    return 0;
}
