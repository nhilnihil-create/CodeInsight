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
#include <cstring>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int k, s;
    cin >> k >> s;
    ll ans = 0;
    rep(i, k+1) rep(j, k+1) {
        if (s - i - j <= k && s - i - j >= 0) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
