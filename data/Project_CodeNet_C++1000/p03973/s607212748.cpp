#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int tmp = 2;
    ll ans = a[0] - 1;

    for (int i = 1; i < n; i++) {
        if (a[i] < tmp) continue;
        if (a[i] == tmp) tmp += 1;
        else {
            ans += (a[i] - 1) / tmp;
        }
    }

    cout << ans << endl;

    return 0;

}
