#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int st = 1;
    ll ans = 3;
    if (s[0] != t[0]) {
        st = 2;
        ans = 6;
    }
    rrep(i, st, s.size()) {
        if (s[i] == t[i]) {
            if (s[i - 1] == t[i - 1]) {
                ans *= 2;
                ans %= (ll)(1e9 + 7);
            }
        } else {
            //i++ forbidden here
            if (s[i - 1] == t[i - 1]) {
                ans *= 2;
                ans %= (ll)(1e9 + 7);
            } else {
                ans *= 3;
                ans %= (ll)(1e9 + 7);
            }
            i++;
        }
    }
    cout << ans % (ll)(1e9 + 7) << endl;
}
