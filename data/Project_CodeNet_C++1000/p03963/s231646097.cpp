#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

long long powll(long long a, long long b) {
    long long ret = 1;
    for (long long i = 0; i < b; i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    long long N, K;
    cin >> N >> K;

    cout << K * powll(K - 1, N - 1) << endl;

    return 0;
}
