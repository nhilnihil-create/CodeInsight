#include <algorithm>
#include <bitset>
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
    ll ans = 0;
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < pow(2, n - 1); i++) {
        int len = 0;
        int st = 0;
        int f = n >= 2 ? 1 << (n - 2) : 0;
        while (f > 0) {
            if ((f & i) > 0) {
                // cout << s.substr(st, len + 1) << ",";
                ans += stoll(s.substr(st, len + 1));
                st += len + 1;
                len = 0;
            } else {
                len++;
            }
            f = f >> 1;
        }
        // cout << s.substr(st, len + 1) << endl;
        ans += stoll(s.substr(st, len + 1));
    }

    cout << ans << endl;

    return 0;
}
