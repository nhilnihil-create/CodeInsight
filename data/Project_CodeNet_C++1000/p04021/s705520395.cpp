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
    vector<pair<ll, int>> a(n);
    rep(i, n) {
        int tmp_a;
        cin >> tmp_a;
        a[i] = make_pair(tmp_a, i);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, n) {
        if (a[i].second % 2 != i % 2) ++ ans; 
    }
    cout << ans/2 << endl;
    return 0;
}
