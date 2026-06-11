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
    string s, t;
    cin >> n >> s >> t;
    int cnt = 0;
    int ofst = 0;
    rep(i, n) {
        bool ok = true;
        rep(j, i+1) {
            if (s[n-1+j-i] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt = i+1;
        }
    }
    cout << 2 * n - cnt << endl;
    return 0;
}
