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
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    rep(i, 1<<(n-1)) {
        ll num = s[0] - '0';
        rep(j, n-1) {
            if ((i>>j) &1) {
                //cout << num << endl;
                ans += num;
                num = s[j+1] - '0';
            }
            else {
                num = num * 10 + s[j+1] - '0';
            }
        }
        //cout << num << endl;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}
