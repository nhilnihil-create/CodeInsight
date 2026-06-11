#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 * 1e7;

vector<ll> vec;
vector<bool> graph[2];

int main() {
    fastInp;

    ll k, n = 1;
    cin >> k;

    ll lft = k;
    vector<ll> ans(50), mns(50);
    n = 50;
    ll addAll = lft / 50, add = 0;
    lft -= addAll * 50;
    for (int i = n - 1; i >= 0; i--) ans[i] = i;
    for (int i = 0; i < n; i++) {
        ans[i] += addAll * 50 - (addAll * (n - 1));
        if (lft > 0) {
            add++;
            mns[i] = 1;
            lft--;
            ans[i] += 50;
        }
    }
    for (int i = 0; i < n; i++) ans[i] -= add - mns[i];
    cout << 50 << "\n";
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}

