#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) cout << (x) << endl
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll st_a[n + 1];
    st_a[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        st_a[i] = st_a[i - 1] + a[i - 1];
    }
    ll stP_a[n + 1];
    stP_a[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        stP_a[i] = stP_a[i - 1] + max(a[i - 1], 0LL);
    }

    ll ans = -1;

    for (int i = 0; i + k - 1 < n; i++) {
        ll tmp = stP_a[n];
        tmp -= stP_a[i + k] - stP_a[i];
        tmp += max(0LL, st_a[i + k] - st_a[i]);
        ans = max(ans, tmp);
    }
    OUT(ans);
}
