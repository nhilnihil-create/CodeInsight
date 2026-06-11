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
    if (a.length() != b.length()) {
        cout << (a.length() > b.length() ? "GREATER" : "LESS") << "\n";
        return;
    } else {
        for (int i = 0 ; i < a.length(); i++) {
            if (a[i] != b[i]) {
                cout << (a[i] > b[i] ? "GREATER" : "LESS") << "\n";
                return;
            }
        }
        cout << "EQUAL\n";
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
