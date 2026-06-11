#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    ans += v[0].first + v[n - 1].first - v[0].first + v[n - 1].second; 

    cout << ans << endl;
    return 0;
}
