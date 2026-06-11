#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    vector<int> L(n * 2);
    rep(i, n * 2) cin >> L.at(i);
    sort(L.begin(), L.end());

    int sum = 0;
    for (int i = L.size() - 1; i >= 0; i -= 2) {
        sum += min(L.at(i), L.at(i - 1));
    }
    cout << sum << endl;
}