#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define MX 1e5


void solve() {
    int x, a, b;
    cin >> x >> a >> b;
    if (a-b >= 0) {
        cout << "delicious\n";
    } else if ((b-a) <= x) {
        cout << "safe\n";
    } else {
        cout << "dangerous\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
