#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;
    vector<int> length(n);
    rep(i, n) cin >> length.at(i);
    sort(length.rbegin(), length.rend());

    int sum = 0;
    for (size_t i = 0; i < k; i++) {
        sum += length.at(i);
    }
    cout << sum << endl;
}