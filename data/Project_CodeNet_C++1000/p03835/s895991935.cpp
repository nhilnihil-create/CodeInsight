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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(i, k+1) rep(j, k+1) {
        if (i + j > s) continue;
        else if (s - (i + j) <= k) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
