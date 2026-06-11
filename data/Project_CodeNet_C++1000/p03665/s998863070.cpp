#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, p, ch = 0;
    ll ans = 1;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a&1) ch = 1;
        ans *= 2;
    }
    if (ch) cout << ans / 2 << endl;
    else if (p) cout << 0 << endl;
    else        cout << ans << endl;
    return 0;
}