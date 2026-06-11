#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)

void solve() {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(bn(v));
    cout << (v[1] == 5 ? "YES" : "NO");
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
