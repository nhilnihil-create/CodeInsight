#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s;
int main() {
    cin >> s;
    int n = s.length();
    string ans = s[0] + to_string(n - 2) + s[n - 1];
    cout << ans << endl;
    return 0;
}
