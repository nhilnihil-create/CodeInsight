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

    ll n, ans = 0;
    n = 7;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    ans += vec[1] * 2;
    vec[1] = 0;

    ll q = 0, add = ans;
    ans += max((vec[3] / 2) * 4 + (vec[4] / 2) * 4 + (vec[0] / 2) * 4, q);
    if (vec[0] > 0 && vec[4] > 0 && vec[3] > 0) {
        vec[0]--;
        vec[4]--;
        vec[3]--;
        q = (vec[3] / 2) * 4 + (vec[4] / 2) * 4 + (vec[0] / 2) * 4 + 6 + add;
    }
    ans = max(ans, q);

    cout << ans / 2;
    return 0;
}