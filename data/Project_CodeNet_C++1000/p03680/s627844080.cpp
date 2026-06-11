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
const ll LINF = 1001002003004005006ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
    }
    vector<bool> flg(n, false);
    int now = 0;
    int cnt = 0;
    flg[0] = true;
    while(1) {
        // cout << now << " " << a[now] << endl;
        // rep(i, n) cout << flg[i];
        // cout << endl;
        if (now == 1) {
            // cout << "test1" << endl;
            cout << cnt << endl;
            return 0;
        }
        if (now == a[now]) {
            // cout << "test2" << endl;
            cout << -1 << endl;
            return 0;
        }
        if (flg[a[now]]) {
            // cout << "test3" << endl;
            cout << -1 << endl;
            return 0;
        }
        ++cnt;
        flg[a[now]] = true;
        now = a[now];
    }
    return 0;
}
