#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    long long n;
    cin >> n;

    int res = 1 << 20;

    auto len = [&](long long x) {
        int res = 0;
        while (x > 0) {
            ++res;
            x /= 10;
        }
        return res;
    };
    for (int i = 1; i * 1LL * i <= n; ++i) {
        if (n % i == 0) {
            res = min(res, max(len(i), len(n / i)));
        }
    }

    cout << res << '\n';

    return 0;
}