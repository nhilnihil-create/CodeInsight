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


int x, a, b;
int main() {
    cin >> x >> a >> b;
    if (b <= a) {
        cout << "delicious" << endl;
    } else if (b - a <= x) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    return 0;
}
