#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string o, e;
    cin >> o >> e;
    for (size_t i = 0; i < o.size(); i++) {
        cout << o.at(i);
        if (e.size() != i)
            cout << e.at(i);
    }
}