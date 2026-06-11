#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int a, b, c;
int main() {
    unordered_set<int> seen;
    cin >> a >> b >> c;
    int d = a % b;
    int r = d;
    while (1) {
        if (r == c) {
            cout << "YES" << endl;
            exit(0);
        }
        if (seen.count(r)) break;
        seen.insert(r);
        r = (r + d) % b;
    }
    cout << "NO" << endl;
    return 0;
}
