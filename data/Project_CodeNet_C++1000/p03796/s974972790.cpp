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

const uint64_t mod = 1000000000 + 7;

int main() {
    int N;
    cin >> N;

    uint64_t ret = 1;
    rep(i, N) {
        ret *= (i+1);
        ret %= mod;
    }
    cout << ret << endl;


    return 0;
}

