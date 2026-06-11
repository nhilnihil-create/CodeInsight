#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define space ' '
typedef long long ll;
typedef long double ld;
const long double PI = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll minCost = 1e9;
    for (int i = -100; i <= 100; ++i) {
        ll cost = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] != i) {
                ll tmp = a[j] - i;
                cost += (tmp * tmp);
            }
        }
        minCost = min(minCost, cost);
    }
    cout << minCost << endl;

    return 0;
}
