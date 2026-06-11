#include <bits/stdc++.h>
 
using namespace std;
 
int ds[100100], dt[100100];
string s, t;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> s >> t;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'A') ds[i + 1] = ds[i] + 1;
        else ds[i + 1] = ds[i] - 1;
    }
    for (int i = 0; i < (int) t.size(); i++) {
        if (t[i] == 'A') dt[i + 1] = dt[i] + 1;
        else dt[i + 1] = dt[i] - 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int v = (ds[b] - ds[a - 1]) - (dt[d] - dt[c - 1]);
        if (v % 3) cout << "NO\n";
        else cout << "YES\n";
    }
}