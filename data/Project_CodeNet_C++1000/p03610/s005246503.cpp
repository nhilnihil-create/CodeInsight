#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

string s;

signed main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    cin >> s;
    rep(i, s.size()) if (i%2==0) cout << s[i];
    cout << endl;
}