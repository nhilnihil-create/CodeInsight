#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    vector<int> roads(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        roads.at(a - 1)++;
        roads.at(b - 1)++;
    }
    for (auto road : roads) cout << road << endl;
}