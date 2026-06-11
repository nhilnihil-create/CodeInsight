#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {
    int N, x, y, ans;
    string s, t;
    
    cin >> N >> s >> t;
    x = s.size();
    y = t.size();

    if (N >= x + y) {
        ans = N;
    }
    else {
        ans = x + y;
        for (int i = 0; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s.substr(i, x) == t.substr(0, j) && x + y - j >= N) {
                    ans = min(x + y - j, ans);
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}