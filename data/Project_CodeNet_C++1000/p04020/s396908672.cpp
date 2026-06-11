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
    A.push_back(0);
    lint ans = 0, sum = 0;
    rep(i, N + 1) {
        if (A[i] == 0) {
            ans += sum / 2;
            sum = 0;
        } else {
            sum += A[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
