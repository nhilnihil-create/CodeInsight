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


    int n;
    cin >> n;
    vector<long long> T(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    auto gcd = [&](long long a, long long b) {
        while (a != 0) {
            b %= a;
            swap(a, b);
        }
        return b;
    };

    auto lcm = [&](long long a, long long b) {
        return a / gcd(a, b) * b;
    };

    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res = lcm(res, T[i]);
    }

    cout << res << '\n';

    return 0;
}