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


    int K, S;
    cin >> K >> S;

    long long res = 0;
    for (int sum = max(0, S - K); sum <= 2 * K && sum <= S; ++sum) {
        int l = max(0, sum - K);
        int r = min(sum, K);
        int cnt = r - l + 1;
        res += max(0, cnt);
    }

    cout << res << '\n';

    return 0;
}