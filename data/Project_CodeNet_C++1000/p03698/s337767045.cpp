#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    string a;
    cin >> a;
    sort(bn(a));
    for (int i = 1; i < a.length(); i++) {
        if (a[i] == a[i-1]) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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
