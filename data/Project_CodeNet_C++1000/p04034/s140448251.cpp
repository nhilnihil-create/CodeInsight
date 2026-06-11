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
    int n, m;
    cin >> n >> m;
    vector<bool> flg(n, false);
    flg[0] = true;
    vector<int> cnt(n, 1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (flg[x]) flg[y] = true;
        ++cnt[y];
        --cnt[x];
        if (cnt[x] == 0) flg[x] = false;
    } 
    int ans = 0;
    rep(i, n) {
        if (flg[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
