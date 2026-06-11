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
int sum, t, mx;
int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> t;
        sum += t;
        mx = max(mx, t);
    }
    cout << sum - mx << endl;
    
    return 0;
}
