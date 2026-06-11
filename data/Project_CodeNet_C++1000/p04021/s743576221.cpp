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
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<pair<int, int>> S(N);
    rep(i, N) S[i] = pair<int, int>{A[i], i};
    sort(S.begin(), S.end());
    int cnt = 0;
    rep(i, N) {
        if (abs(S[i].second - i) & 1) ++cnt;
    }
    cout << cnt / 2 << "\n";
    return 0;
}
