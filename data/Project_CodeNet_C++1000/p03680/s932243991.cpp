#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define MX 1e5


void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    int x = 1;
    while(x != 2 && cnt < n+1) {
        x = v[x];
        cnt++;
    }
    cout << (cnt == n+1 ? -1 : cnt) << "\n";
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
