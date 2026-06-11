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

constexpr int kMOD = 1000000007;
constexpr uint64_t kINF = 0xFFFFFFFFFFFFFFFF;

int main() {
    int N, P;
    cin >> N >> P;
    int count[2] = {0, 0};

    int tmp;
    rep(i, N) {
        cin >> tmp;
        count[tmp % 2]++;
    }

    uint64_t odds  = 0;
    uint64_t evens = 0;
    evens = 1ull << count[0];
    if(P == 0) {
        if(count[1] == 0) {
            odds = 1;
        } else {
            odds = 1ull << (uint64_t)(count[1]-1);
        }
    } else {
        // P = 1;
        
        if(count[1] < 2) {
            odds = 0;
        } else {
            odds = 1ull << (uint64_t)(count[1]-1);
        }
    }

    // cout << count[0] << " " << count[1] << endl;
    cout << (uint64_t)(odds) * (uint64_t)evens << endl;
    return 0;
}

