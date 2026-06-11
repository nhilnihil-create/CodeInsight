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
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    ll q1 = q * 4LL;
    ll h1 = h * 2LL;
    ll cost = 0;
    cost = n / 2LL * min({q1*2, h1*2, s*2, d});
    n -= n / 2LL * 2LL;
    if (n) cost += min({q1, h1, s});
    cout << cost << endl;
    return 0;
}
