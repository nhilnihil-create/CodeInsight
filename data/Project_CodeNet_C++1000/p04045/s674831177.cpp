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

    int n, K;
    cin >> n >> K;
    vector<int> bad(10, false);
    for (int i = 0; i < K; ++i) {
        int x;
        cin >> x;
        bad[x] = true;
    }
    
    auto ok = [&](int x) {
        while (x != 0) {
            if (bad[x % 10]) {
                return false;
            }
            x /= 10;
        }
        return true;
    };


    int res = -1;

    for (int i = n; ;++i) {
        if (ok(i)) {
            res = i;
            break;
        }
    }


    cout << res << '\n';


    return 0;
}