#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b+2; i++) {
        cout << '#';
    }
    cout << "\n";
    for (int i = 0; i < a; i++) {
        cout << '#';
        string s;
        cin >> s;
        cout << s;
        cout << '#' << "\n";
    }
    for (int i = 0; i < b+2; i++) {
        cout << '#';
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
