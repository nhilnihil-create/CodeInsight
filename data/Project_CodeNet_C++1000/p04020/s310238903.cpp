#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll SIZE = 1e5 + 10;

vector<vector<ll>> vec;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    fastInp;

    ll n;
    cin >> n;

    ll pr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        ll q = min(num, pr);
        ans += q;
        pr = 0;
        num -= q;
        ans += num / 2;
        num %= 2;
        pr = num;
    }

    cout << ans;
    return 0;
}