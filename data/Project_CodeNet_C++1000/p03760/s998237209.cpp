#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    string a, b;
    cin >> a >> b;
    string ans;
    for (int i = 0; i < min(a.length(), b.length()); i++) {
        ans += a[i];
        ans += b[i];
    }
    if (a.length() != b.length()) {
        ans += (a.length() > b.length() ? a[a.length()-1] : b[b.length()-1]);
    }
    cout << ans << "\n";
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
