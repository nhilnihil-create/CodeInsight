#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool is_all_even = true;
    rep(i, n) {
        if (a[i] % 2 != 0) is_all_even = false;
    }

    ll ans = pow(2, n);

    if (is_all_even) {
        if (p == 0) cout << ans << endl;
        else cout << 0 << endl;
    }
    else {
        cout << ans / 2 << endl;
    }
    return 0;
}
