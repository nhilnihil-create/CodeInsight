#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)

void solve() {
    int x, y;
    cin >> x >> y;
    vector<string> v;
    for (int i = 0; i < x; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    sort(bn(v));
    for (string a : v) {
        cout << a;
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
