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
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        ++mp[a];
    }
    int ans = 0;
    for (auto p: mp) {
        if (p.second % 2 == 1) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
