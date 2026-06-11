#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x.at(i);

    int total = 0;
    for (auto p : x) {
        total += min(abs(p - 0), abs(p - k)) * 2;
    }
    cout << total << endl;
}