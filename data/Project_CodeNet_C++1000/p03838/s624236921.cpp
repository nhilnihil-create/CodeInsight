#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

ll q;
vector<ll> vec;

int main() {
    fastInp;

    ll a, b;
    cin >> a >> b;

    ll ans = INT64_MAX;
    if (-a <= b) {
        ans = min(ans, abs(b + a) + 1);
    }
    if (a <= b) {
        ans = min(ans, abs(b - a));
    }
    if (-a <= -b) {
        ans = min(ans, (-b + a) + 2);
    }
    if (a <= -b) {
        ans = min(ans, -b - a + 1);
    }
    cout << ans;
    return 0;
}