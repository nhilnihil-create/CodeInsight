#include <algorithm>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

ll to5(ll a) { return a * a * a * a * a; }

int main() {
    ios::sync_with_stdio(false);
    int k, s;
    ll ans = 0;
    cin >> k >> s;

    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            if (x + y <= s && x + y + k >= s)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
