#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    uint64_t N;
    cin >> N;
    vector<uint64_t> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    vector<uint64_t> accum = A;
    rep(i, N-1) {
        accum[i+1] += accum[i];
    }
    int64_t ret = 0;
    rep(i, N-1) {
        if(accum[i]*2 >= A[i+1]) {
            ret++;
        } else {
            ret = 0;
        }
    }
    ret++;
    cout << ret << endl;

    return 0;
}
