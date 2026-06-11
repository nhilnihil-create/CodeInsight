#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    map<int, int> ma;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;

        ma[a]++;
    }

    int sum = 0;

    for (auto m : ma) {
        if (m.second > 1) {
            sum += m.second - 1;
        }
    }

    if (sum % 2 == 0) {
        cout << n - sum << endl;
    } else {
        cout << n - sum - 1 << endl;
    }
}