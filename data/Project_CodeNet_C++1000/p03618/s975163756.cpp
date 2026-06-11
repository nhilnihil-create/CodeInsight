#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define all(a) (a).begin(), (a).end()

#define sz(a) (int) (a).size()

#define int long long

int c[200000][26];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    c[n-1][s[n-1]-'a']++;
    for (int i=n-2; i>-1; i--) {
        for (int j=0; j<26; j++) {
            c[i][j] = c[i+1][j];
        }
        c[i][s[i]-'a']++;
    }
    int ans = 0;
    for (int i=0; i<n-1; i++) {
        ans += n-i-1-c[i+1][s[i]-'a'];
    }
    cout << ans+1;
    return 0;
}
